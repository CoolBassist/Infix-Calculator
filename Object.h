//
// Created by errey on 05/09/2022.
//

#ifndef INFIXCALC_OBJECT_H
#define INFIXCALC_OBJECT_H


#include <string>
#include "Token.h"

class Object {
public:
    Type token_type;
    int value;
    std::string op;
    std::string literal;

    Object(Type, int, std::string);
    Object(Type, std::string, std::string);
};


#endif //INFIXCALC_OBJECT_H
