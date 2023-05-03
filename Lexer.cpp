//
// Created by CoolBassist on 05/09/2022.
//

#include <iostream>
#include "Lexer.h"
#include "Token.h"
#include "Error.h"

Lexer::Lexer(std::string input) {
    this->input = input;
    this->position = 0;
}

void Lexer::skip_whitespace(){
    while(input[position] == ' ' || input[position] == '\t' || input[position] == '\n' || input[position] == '\r') {
        position++;
    }
}

std::string Lexer::read_integer_literal() {
    std::string integer_literal = "";
    while(std::isdigit(input[position])){
        integer_literal += input[position];
        position++;
    }

    return integer_literal;
}

std::vector<Token> Lexer::get_tokens() {
    std::vector<Token> tokens;

    while(position < input.size()){
        skip_whitespace();
        switch (input[position]) {
            case '+':
                tokens.emplace_back(ADD, std::string(1, input[position]), position);
                position++;
                break;
            case '-':
                if(tokens.size() == 0){
                    tokens.emplace_back(NEG, std::string(1, input[position]), position);
                }else if(tokens.back().get_type() == INT || tokens.back().get_type() == RPAREN){
                    tokens.emplace_back(SUB, std::string(1, input[position]), position);
                }else{
                    tokens.emplace_back(NEG, std::string(1, input[position]), position);
                }
                position++;
                break;
            case '*':
                tokens.emplace_back(MULT, std::string(1, input[position]), position);
                position++;
                break;
            case '/':
                tokens.emplace_back(DIV, std::string(1, input[position]), position);
                position++;
                break;
            case '^':
                tokens.emplace_back(EXP, std::string(1, input[position]), position);
                position++;
                break;
            case '(':
                tokens.emplace_back(LPAREN, std::string(1, input[position]), position);
                position++;
                break;
            case ')':
                tokens.emplace_back(RPAREN, std::string(1, input[position]), position);
                position++;
                break;
            case '.':
                tokens.emplace_back(DOT, std::string(1, input[position]), position);
                position++;
                break;
            default:
                if(std::isdigit(input[position])){
                    std::string result = read_integer_literal();
                    if(result.compare("")){
                        tokens.emplace_back(INT, result, position);
                    }else{
                        errors.emplace_back(UNEXPECTED_TOKEN, std::string(1, input[position]), position);
                        position++;
                    }
                }else if(std::isalpha(input[position])){
                    std::string result = read_identifier();

                    if(!result.compare("sin")){
                        tokens.emplace_back(SIN, result, position-3);
                    }else if(!result.compare("cos")){
                        tokens.emplace_back(COS, result, position-3);
                    }else if(!result.compare("tan")){
                        tokens.emplace_back(TAN, result, position-3);
                    }else if(!result.compare("log")) {
                        tokens.emplace_back(LOG, result, position-3);
                    }else if(!result.compare("sqrt")){
                        tokens.emplace_back(SQR, result, position-4);
                    }else{
                        errors.emplace_back(UNKNOWN_IDENTIFIER, result, position-result.size());
                        position++;
                    }
                }else{
                    errors.emplace_back(UNEXPECTED_TOKEN, std::string(1, input[position]), position);
                    position++;
                }
        }
    }

    return tokens;
}

std::string Lexer::read_identifier() {
    std::string identifier = "";
    while(std::isalpha(input[position])){
        identifier += input[position];
        position++;
    }
    return identifier;
}

std::vector<Error> Lexer::get_errors() {
    return errors;
}
