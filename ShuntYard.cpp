//
// Created by errey on 05/09/2022.
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
            case INT:
                output.push(Object(INT, std::stoi(tokens[position].get_literal()), tokens[position].get_literal()));
                position++;
                break;
            case OP:
                if (tokens[position].get_literal() == "+" || tokens[position].get_literal() == "-") {
                    while (operators.size() != 0 &&
                           (operators.top().literal == "*" || operators.top().literal == "/")) {
                        Object cur_object = operators.top();
                        output.push(cur_object);
                        operators.pop();
                    }
                }
                operators.push(Object(OP, tokens[position].get_literal(), tokens[position].get_literal()));
                position++;
                break;
            case LPAREN:
                operators.push(Object(OP, tokens[position].get_literal(), tokens[position].get_literal()));
                position++;
                break;
            case RPAREN:
                if(operators.size() != 0) {
                    while (operators.size() != 0 && operators.top().literal.compare("(") != 0) {
                        output.push(operators.top());
                        operators.pop();
                    }
                    operators.pop();
                }
                position++;
                break;
        }
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
