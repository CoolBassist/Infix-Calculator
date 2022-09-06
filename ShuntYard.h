//
// Created by CoolBassist on 05/09/2022.
//

#ifndef INFIXCALC_SHUNTYARD_H
#define INFIXCALC_SHUNTYARD_H


#include <stack>
#include <queue>
#include "Token.h"
#include "Object.h"

class ShuntYard {
private:
    std::vector<Token> tokens;
    std::stack<Object> operators;
    std::queue<Object> output;
    int position;
public:
    ShuntYard(std::vector<Token>);
    std::vector<Object> to_infix();
};


#endif //INFIXCALC_SHUNTYARD_H
