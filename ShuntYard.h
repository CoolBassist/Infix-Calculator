//
// Created by CoolBassist on 05/09/2022.
//

#ifndef INFIXCALC_SHUNTYARD_H
#define INFIXCALC_SHUNTYARD_H


#include <stack>
#include <queue>
#include <variant>
#include "Token.h"
#include "Object.h"

class ShuntYard {
private:
    std::vector<Token> tokens;
    std::stack<OpObject> operators;
    std::queue<std::variant<IntObject, OpObject>> output;
    int position;
public:
    ShuntYard(std::vector<Token>);
    std::vector<std::variant<IntObject, OpObject>> to_infix();
};


#endif //INFIXCALC_SHUNTYARD_H
