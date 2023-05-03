//
// Created by CoolBassist on 25/09/2022.
//

#ifndef INFIXCALC_ERROR_H
#define INFIXCALC_ERROR_H


#include <string>
#include "Token.h"

enum error_type {UNEXPECTED_TOKEN, UNKNOWN_IDENTIFIER, SYNTAX_ERROR, EXPECTED_TOKEN, MISSING_OPEN_BRACKET, MISSING_CLOSING_BRACKET, NO_EXPRESSION, DIV_BY_0};

class Error {
private:
    error_type type;
    std::string token;
    int position;
public:
    Error(error_type, std::string, int);
    std::string get_error();
    int get_position();
};


#endif //INFIXCALC_ERROR_H
