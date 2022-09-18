//
// Created by CoolBassist on 05/09/2022.
//

#ifndef INFIXCALC_EVALUATOR_H
#define INFIXCALC_EVALUATOR_H


#include <vector>
#include <stack>
#include <variant>
#include "Object.h"

class Evaluator {
private:
    std::vector<std::variant<IntObject, OpObject>> objects;
    std::stack<IntObject> output;
public:
    Evaluator(std::vector<std::variant<IntObject, OpObject>>);
    int get_result();
};


#endif //INFIXCALC_EVALUATOR_H
