//
// Created by CoolBassist on 05/09/2022.
//

#ifndef INFIXCALC_OBJECT_H
#define INFIXCALC_OBJECT_H

#include <string>
#include <variant>
#include "Token.h"

class IntObject {
private:
    int value;
    std::string literal;
public:
    IntObject(int, std::string);
    int get_value();
    std::string get_literal();
};

class OpObject {
private:
    Type type;
    std::string literal;
public:
    OpObject(Type, std::string);
    Type get_type();
    std::string get_literal();
};

class RealObject{
private:
    double value;
    std::string literal;
public:
    RealObject(double, std::string);
    double get_value();
    std::string get_literal();
};

typedef std::variant<IntObject, OpObject, RealObject> Object ;
typedef std::variant<IntObject, RealObject> NumberObject ;

#endif //INFIXCALC_OBJECT_H
