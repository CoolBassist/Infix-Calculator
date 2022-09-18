//
// Created by CoolBassist on 05/09/2022.
//

#include "Object.h"

IntObject::IntObject(int value, std::string literal) {
    this->value = value;
    this->literal = literal;
}

int IntObject::get_value() {
    return value;
}

std::string IntObject::get_literal() {
    return literal;
}

OpObject::OpObject(Type type, std::string literal) {
    this->type = type;
    this->literal = literal;
}

Type OpObject::get_type() {
    return type;
}

std::string OpObject::get_literal() {
    return literal;
}
