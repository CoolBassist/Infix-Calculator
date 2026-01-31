//
// Created by CoolBassist on 05/09/2022.
//

#include <iostream>
#include <variant>
#include "ShuntYard.h"
#include "Object.h"
#include <spdlog/spdlog.h>

ShuntYard::ShuntYard(std::vector<Token> tokens) {
    this->tokens = tokens;
    position = 0;
}

std::vector<Object> ShuntYard::to_infix() {
    std::vector<Object> objects;
    std::stack<std::pair<Type, int>> brackets;
    int open_brackets = 0;

    while (position < tokens.size()) {
        spdlog::info("Processing token: {} at position {}", tokens[position].get_literal(), tokens[position].get_position());
        switch (tokens[position].get_type()) {
            case NEG:
                position++;
                output.push(IntObject(0-std::stoi(tokens[position].get_literal()), "-" + tokens[position].get_literal()));
                break;
            case INT:
                if(position == tokens.size()-1 || tokens[position+1].get_type() != DOT) {
                    output.push(IntObject(std::stoi(tokens[position].get_literal()), tokens[position].get_literal()));
                }else{
                    output.push(RealObject(std::stod(tokens[position].get_literal() + "." + tokens[position+2].get_literal()), tokens[position].get_literal() + "." + tokens[position+2].get_literal()));
                    position++;
                    position++;
                }
                break;
            case ADD:
            case SUB:
            case MULT:
            case DIV:
            case EXP:
                while((!operators.empty()) && (precs[operators.top().get_type()] > precs[tokens.front().get_type()])){
                    OpObject cur_object = operators.top();
                    output.push(cur_object);
                    operators.pop();
                }
            case LPAREN:
                if(tokens[position].get_type() == LPAREN){
                    open_brackets++;
                    brackets.push(std::pair(tokens[position].get_type(), tokens[position].get_position()));
                }
            case SIN:
            case COS:
            case TAN:
            case LOG:
            case SQR:
                operators.push(OpObject(tokens[position].get_type(), tokens[position].get_literal()));
                if(!expect_peek(INT) && !expect_peek(LPAREN)){
                    if(position != tokens.size()-1) {
                        errors.emplace_back(SYNTAX_ERROR, tokens[position+1].get_literal(),
                                            tokens[position+1].get_position());
                    }else{
                        errors.emplace_back(EXPECTED_TOKEN, "EOL", tokens.size());
                    }
                }
                break;
            case RPAREN:
                if(brackets.empty()){
                    errors.emplace_back(MISSING_OPEN_BRACKET, "(", tokens[position].get_position());
                    break;
                }else if(brackets.top().first != LPAREN){
                    errors.emplace_back(MISSING_OPEN_BRACKET, "(", tokens[position].get_position());
                    brackets.pop();
                }else{
                    brackets.pop();
                }

                if(!operators.empty()) {
                    while (!operators.empty() && operators.top().get_literal() != "(") {
                        output.push(operators.top());
                        operators.pop();
                    }
                    operators.pop();
                }
                open_brackets--;
                break;
        }

        position++;
    }

    while (!operators.empty()) {
        output.push(operators.top());
        operators.pop();
    }

    while (!output.empty()) {
        objects.push_back(output.front());
        output.pop();
    }

    while(!brackets.empty()){
        errors.emplace_back(MISSING_CLOSING_BRACKET, ")", brackets.top().second);
        brackets.pop();
    }

    return objects;
}



bool ShuntYard::expect_peek(Type type) {
    if(position == tokens.size()-1 || tokens[position+1].get_type() == type){
        return false;
    }

    return true;
}

std::vector<Error> ShuntYard::get_errors() {
    return errors;
}
