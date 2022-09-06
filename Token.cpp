//
// Created by CoolBassist on 05/09/2022.
//

#include "Token.h"

Token::Token(Type token_type, std::string literal) {
    this->token_type = token_type;
    this->literal = literal;
}

Type Token::get_type() {
    return this->token_type;
}

std::string Token::get_literal() {
    return this->literal;
}
