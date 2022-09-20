//
// Created by CoolBassist on 05/09/2022.
//

#include <iostream>
#include "Lexer.h"
#include "Token.h"

Lexer::Lexer(std::string input) {
    std::string inp = "";
    for(char c: input){
        if(c == ' ' || c == '\t' || c == '\n' || c == '\r'){
            continue;
        }
        inp += c;
    }
    this->input = inp;
    this->position = 0;
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
        switch (input[position]) {
            case '+':
                tokens.push_back(Token(ADD, std::string(1, input[position])));
                position++;
                break;
            case '-':
                if(tokens.size() == 0 || (tokens.back().get_type() != RPAREN && !std::isdigit(input[position-1]))){
                    tokens.push_back(Token(NEG, std::string(1, input[position])));
                }else {
                    tokens.push_back(Token(SUB, std::string(1, input[position])));
                }
                position++;
                break;
            case '*':
                tokens.push_back(Token(MULT, std::string(1, input[position])));
                position++;
                break;
            case '/':
                tokens.push_back(Token(DIV, std::string(1, input[position])));
                position++;
                break;
            case '^':
                tokens.push_back(Token(EXP, std::string(1, input[position])));
                position++;
                break;
            case '(':
                tokens.push_back(Token(LPAREN, std::string(1, input[position])));
                position++;
                break;
            case ')':
                tokens.push_back(Token(RPAREN, std::string(1, input[position])));
                position++;
                break;
            case '.':
                tokens.push_back(Token(DOT, std::string(1, input[position])));
                position++;
                break;
            default:
                if(std::isdigit(input[position])){
                    std::string result = read_integer_literal();
                    if(result.compare("")){
                        tokens.push_back(Token(INT, result));
                    }else{
                        std::cout << "Unexpected token " << input[position] << "\n";
                        tokens.clear();
                        return tokens;
                    }
                }else if(std::isalpha(input[position])){
                    std::string result = read_identifier();

                    if(!result.compare("sin")){
                        tokens.push_back(Token(SIN, result));
                    }else if(!result.compare("cos")){
                        tokens.push_back(Token(COS, result));
                    }else if(!result.compare("tan")){
                        tokens.push_back(Token(TAN, result));
                    }else if(!result.compare("log")){
                        tokens.push_back(Token(LOG, result));
                    }else{
                        std::cout << "Unexpected token " << input[position] << "\n";
                        tokens.clear();
                        return tokens;
                    }
                }else{
                    std::cout << "Unexpected token " << input[position] << "\n";
                    tokens.clear();
                    return tokens;
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
