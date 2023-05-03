//
// Created by CoolBassist on 05/09/2022.
//

#ifndef INFIXCALC_TOKEN_H
#define INFIXCALC_TOKEN_H


#include <string>

enum Type {INT, ADD, SUB, MULT, DIV, EXP, LPAREN, RPAREN, NEG, SIN, COS, TAN, DOT, LOG, SQR};

class Token {
private:
    std::string literal;
    Type token_type;
    int position;
public:
    Token(Type, std::string, int);
    Type get_type();
    std::string get_literal();
    int get_position();
};

#endif //INFIXCALC_TOKEN_H
