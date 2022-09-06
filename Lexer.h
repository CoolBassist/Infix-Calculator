//
// Created by errey on 05/09/2022.
//

#ifndef INFIXCALC_LEXER_H
#define INFIXCALC_LEXER_H


#include <vector>
#include "Token.h"

class Lexer {
private:
    int position;
    std::string input;
    void skip_whitespace();
    std::vector<Token> parse_expression();
    std::vector<Token> parse_infix_expression();
    std::vector<Token> parse_prefix_expression();
    std::vector<Token> cleanup_tokens(std::vector<Token>);
    std::string read_integer_literal();
public:
    Lexer(std::string);
    std::vector<Token> get_tokens();
};


#endif //INFIXCALC_LEXER_H
