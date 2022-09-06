//
// Created by CoolBassist on 05/09/2022.
//

#include <iostream>
#include "ShuntYard.h"

ShuntYard::ShuntYard(std::vector<Token> tokens) {
    this->tokens = tokens;
    position = 0;
}

std::vector<Object> ShuntYard::to_infix() {
    std::vector<Object> objects;

    while (position < tokens.size()) {
        switch (tokens[position].get_type()) {
            case NEG:
                position++;
                output.push(Object(INT, 0-std::stoi(tokens[position].get_literal()), "-" + tokens[position].get_literal()));
                break;
            case INT:
                output.push(Object(INT, std::stoi(tokens[position].get_literal()), tokens[position].get_literal()));
                break;
            case ADD:
            case SUB:
                while (operators.size() != 0 &&
                        (operators.top().literal == "*" || operators.top().literal == "/")) {
                    Object cur_object = operators.top();
                    output.push(cur_object);
                    operators.pop();
                }
            case MULT:
            case DIV:
                while(operators.size() != 0 && (operators.top().literal == "^" || operators.top().literal == "sin" || operators.top().literal == "cos" || operators.top().literal == "tan")){
                    Object cur_object = operators.top();
                    output.push(cur_object);
                    operators.pop();
                }
            case EXP:
            case LPAREN:
                operators.push(Object(tokens[position].get_type(), tokens[position].get_literal(), tokens[position].get_literal()));
                break;
            case RPAREN:
                if(operators.size() != 0) {
                    while (operators.size() != 0 && operators.top().literal.compare("(") != 0) {
                        output.push(operators.top());
                        operators.pop();
                    }
                    operators.pop();
                }
                break;
            case SIN:
            case COS:
            case TAN:
                operators.push(Object(tokens[position].get_type(), tokens[position].get_literal(), tokens[position].get_literal()));
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
