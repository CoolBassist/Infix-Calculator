//
// Created by errey on 05/09/2022.
//

#include <iostream>
#include "Lexer.h"
#include "Token.h"

Lexer::Lexer(std::string input) {
    this->input = input;
    this->position = 0;
}

std::vector<Token> Lexer::get_tokens() {
    std::vector<Token> tokens;

    while(position < input.size()){
        skip_whitespace();
        switch (input[position]) {
            case '+':
                tokens.push_back(Token(OP, std::string(1, input[position])));
                position++;
                break;
            case '-':
                tokens.push_back(Token(OP, std::string(1, input[position])));
                position++;
                break;
            case '*':
                tokens.push_back(Token(OP, std::string(1, input[position])));
                position++;
                break;
            case '/':
                tokens.push_back(Token(OP, std::string(1, input[position])));
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
            default:
                if(std::isdigit(input[position])){
                    std::string result = read_integer_literal();
                    if(result.compare("")){
                        tokens.push_back(Token(INT, result));
                    }else{
                        tokens.clear();
                        return tokens;
                    }
                }else{
                    tokens.clear();
                    return tokens;
                }
        }
    }

    return tokens;
}

std::string Lexer::read_integer_literal() {
    std::string integer_literal = "";
    while(std::isdigit(input[position])){
        integer_literal += input[position];
        position++;
    }
    return integer_literal;
}

void Lexer::skip_whitespace() {
    while(input[position] == ' ' || input[position] == '\t' || input[position] == '\n' || input[position] == '\r'){
        position++;
    }
}


