//
// Created by CoolBassist on 05/09/2022.
//

#ifndef INFIXCALC_TOKEN_H
#define INFIXCALC_TOKEN_H


#include <string>

enum Type {INT, ADD, SUB, MULT, DIV, EXP, LPAREN, RPAREN, NEG, SIN, COS, TAN, DOT};

class Token {
private:
    std::string literal;
    Type token_type;
public:
    Token(Type, std::string);
    Type get_type();
    std::string get_literal();
};

#endif //INFIXCALC_TOKEN_H
