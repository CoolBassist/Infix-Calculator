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

std::vector<Token> Lexer::get_tokens() {
    std::vector<Token> tokens;

    while(position < input.size()){
        skip_whitespace();
        switch (input[position]) {
            case '+':
                tokens.push_back(Token(ADD, std::string(1, input[position])));
                position++;
                break;
            case '-':
                tokens.push_back(Token(SUB, std::string(1, input[position])));
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

    return cleanup_tokens(tokens);
}

std::vector<Token> Lexer::cleanup_tokens(std::vector<Token> tokens) {
    std::vector<Token> new_tokens;

    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i].get_type() != SUB){
            new_tokens.push_back(tokens[i]);
        }else{
            if(i == 0 || (tokens[i-1].get_type() != RPAREN && tokens[i+1].get_type() == INT)){
                new_tokens.push_back(Token(INT, "-" + tokens[i+1].get_literal()));
                i++;
            }else{
                new_tokens.push_back(tokens[i]);
            }
        }
    }

    return new_tokens;
}