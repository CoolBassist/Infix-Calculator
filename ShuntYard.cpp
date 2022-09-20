//
// Created by CoolBassist on 05/09/2022.
//

#include <iostream>
#include <variant>
#include "ShuntYard.h"

ShuntYard::ShuntYard(std::vector<Token> tokens) {
    this->tokens = tokens;
    position = 0;
}

std::vector<std::variant<IntObject, OpObject, RealObject>> ShuntYard::to_infix() {
    std::vector<std::variant<IntObject, OpObject, RealObject>> objects;

    while (position < tokens.size()) {
        switch (tokens[position].get_type()) {
            case NEG:
                position++;
                output.push(IntObject(0-std::stoi(tokens[position].get_literal()), "-" + tokens[position].get_literal()));
                break;
            case INT:
                if(position == tokens.size()-2 || tokens[position+1].get_type() != DOT) {
                    output.push(IntObject(std::stoi(tokens[position].get_literal()), tokens[position].get_literal()));
                }else{
                    output.push(RealObject(std::stod(tokens[position].get_literal() + "." + tokens[position+2].get_literal()), tokens[position].get_literal() + "." + tokens[position+2].get_literal()));
                    position++;
                    position++;
                }
                break;
            case ADD:
            case SUB:
                while (operators.size() != 0 &&
                        (operators.top().get_type() == MULT || operators.top().get_type() == DIV || operators.top().get_type() == SIN || operators.top().get_type() == COS || operators.top().get_type() == TAN || operators.top().get_type() == EXP || operators.top().get_type() == LOG)) {
                    OpObject cur_object = operators.top();
                    output.push(cur_object);
                    operators.pop();
                }
            case MULT:
            case DIV:
                while(operators.size() != 0 && (operators.top().get_type() == EXP || operators.top().get_type() == LOG || operators.top().get_type() == SIN || operators.top().get_type() == COS || operators.top().get_type() == TAN)){
                    OpObject cur_object = operators.top();
                    output.push(cur_object);
                    operators.pop();
                }
            case EXP:
                while(operators.size() != 0 && (operators.top().get_type() == SIN || operators.top().get_type() == COS || operators.top().get_type() == TAN || operators.top().get_type() == LOG)){
                    OpObject cur_object = operators.top();
                    output.push(cur_object);
                    operators.pop();
                }
            case LPAREN:
            case SIN:
            case COS:
            case TAN:
            case LOG:
                operators.push(OpObject(tokens[position].get_type(), tokens[position].get_literal()));
                break;
            case RPAREN:
                if(operators.size() != 0) {
                    while (operators.size() != 0 && operators.top().get_literal().compare("(") != 0) {
                        output.push(operators.top());
                        operators.pop();
                    }
                    operators.pop();
                }
                break;
        }

        position++;
    }

    while (operators.size() != 0) {
        output.push(operators.top());
        operators.pop();
    }

    while (output.size() != 0) {
        objects.push_back(output.front());
        output.pop();
    }

    return objects;
}
