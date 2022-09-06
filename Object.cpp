//
// Created by CoolBassist on 05/09/2022.
//

#include "Object.h"

Object::Object(Type token_type, int value, std::string literal) {
    this->token_type = token_type;
    this->value = value;
    this->literal = literal;
}

Object::Object(Type token_type, std::string op, std::string literal) {
    this->token_type = token_type;
    this->op = op;
    this->literal = literal;
}
