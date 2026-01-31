//
// Created by CoolBassist on 05/09/2022.
//

#ifndef INFIXCALC_EVALUATOR_H
#define INFIXCALC_EVALUATOR_H


#include <vector>
#include <stack>
#include <variant>
#include "Object.h"
#include <tuple>

class Evaluator {
private:
    std::vector<Object> objects;
    std::stack<NumberObject> output;
    std::tuple<double, double, bool> get_numbers();
    std::tuple<double, bool> get_single_number();
public:
    Evaluator(std::vector<Object>);
    double get_result();
};


#endif //INFIXCALC_EVALUATOR_H
