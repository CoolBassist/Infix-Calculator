//
// Created by CoolBassist on 05/09/2022.
//

#ifndef INFIXCALC_EVALUATOR_H
#define INFIXCALC_EVALUATOR_H


#include <vector>
#include <stack>
#include "Object.h"

class Evaluator {
private:
    std::vector<Object> objects;
    std::stack<Object> output;
public:
    Evaluator(std::vector<Object>);
    int get_result();
};


#endif //INFIXCALC_EVALUATOR_H
