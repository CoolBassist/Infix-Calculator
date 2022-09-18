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

std::vector<std::variant<IntObject, OpObject>> ShuntYard::to_infix() {
    std::vector<std::variant<IntObject, OpObject>> objects;

    while (position < tokens.size()) {
        switch (tokens[position].get_type()) {
            case NEG:
                position++;
                output.push(IntObject(0-std::stoi(tokens[position].get_literal()), "-" + tokens[position].get_literal()));
                break;
            case INT:
                output.push(IntObject(std::stoi(tokens[position].get_literal()), tokens[position].get_literal()));
                break;
            case ADD:
            case SUB:
                while (operators.size() != 0 &&
                        (operators.top().get_literal() == "*" || operators.top().get_literal() == "/")) {
                    OpObject cur_object = operators.top();
                    output.push(cur_object);
                    operators.pop();
                }
            case MULT:
            case DIV:
                while(operators.size() != 0 && (operators.top().get_literal() == "^")){
                    OpObject cur_object = operators.top();
                    output.push(cur_object);
                    operators.pop();
                }
            case EXP:
            case LPAREN:
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
