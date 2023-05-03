//
// Created by CoolBassist on 05/09/2022.
//

#include "Token.h"

Token::Token(Type token_type, std::string literal, int position) {
    this->token_type = token_type;
    this->literal = literal;
    this->position = position;
}

Type Token::get_type() {
    return this->token_type;
}

std::string Token::get_literal() {
    return this->literal;
}

int Token::get_position() {
    return position;
}
