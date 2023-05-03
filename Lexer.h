//
// Created by CoolBassist on 05/09/2022.
//

#ifndef INFIXCALC_LEXER_H
#define INFIXCALC_LEXER_H


#include <vector>
#include "Token.h"
#include "Error.h"

class Lexer {
private:
    int position;
    std::vector<Error> errors;
    std::string input;
    void skip_whitespace();
    std::string read_integer_literal();
    std::string read_identifier();
public:
    Lexer(std::string);
    std::vector<Token> get_tokens();
    std::vector<Error> get_errors();
};


#endif //INFIXCALC_LEXER_H
