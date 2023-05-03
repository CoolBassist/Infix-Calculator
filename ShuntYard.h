//
// Created by CoolBassist on 05/09/2022.
//

#ifndef INFIXCALC_SHUNTYARD_H
#define INFIXCALC_SHUNTYARD_H


#include <stack>
#include <queue>
#include <variant>
#include <unordered_map>
#include "Token.h"
#include "Object.h"
#include "Error.h"

enum prec {SUM, PRODUCT, EXPR, FUNC};

class ShuntYard {
private:
    std::vector<Token> tokens;
    std::stack<OpObject> operators;
    std::queue<std::variant<IntObject, OpObject, RealObject>> output;
    std::vector<Error> errors;
    std::unordered_map<Type, prec> precs {{ADD, SUM}, {SUB, SUM}, {MULT, PRODUCT}, {DIV, PRODUCT}, {SIN, FUNC}, {COS, FUNC}, {TAN, FUNC}, {LOG, FUNC}, {SQR, FUNC}, {EXP, EXPR}};

    int position;
public:
    ShuntYard(std::vector<Token>);
    std::vector<std::variant<IntObject, OpObject, RealObject>> to_infix();
    std::vector<Error> get_errors();
    bool expect_peek(Type);
};


#endif //INFIXCALC_SHUNTYARD_H
