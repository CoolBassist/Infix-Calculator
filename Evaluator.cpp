//
// Created by CoolBassist on 05/09/2022.
//
#include "Evaluator.h"
#include <cmath>
#include <variant>
#include <iostream>

Evaluator::Evaluator(std::vector<std::variant<IntObject, OpObject>> objects) {
    this->objects = objects;
}

int Evaluator::get_result() {
    int num1, num2;
    for (std::variant<IntObject, OpObject> obj: objects) {
        if (std::holds_alternative<IntObject>(obj)) {
            output.push(std::get<IntObject>(obj));
        } else {
            switch (std::get<OpObject>(obj).get_type()) {
                case ADD:
                    num2 = output.top().get_value();
                    output.pop();
                    num1 = output.top().get_value();
                    output.pop();
                    output.push(IntObject(num1 + num2, std::to_string(num1 + num2)));
                    break;

                case SUB:
                    num2 = output.top().get_value();
                    output.pop();
                    num1 = output.top().get_value();
                    output.pop();
                    output.push(IntObject(num1 - num2, std::to_string(num1 - num2)));
                    break;

                case MULT:
                    num2 = output.top().get_value();
                    output.pop();
                    num1 = output.top().get_value();
                    output.pop();
                    output.push(IntObject(num1 * num2, std::to_string(num1 * num2)));
                    break;

                case DIV:
                    num2 = output.top().get_value();
                    output.pop();
                    num1 = output.top().get_value();
                    output.pop();
                    output.push(IntObject(num1 / num2, std::to_string(num1 / num2)));
                    break;

                case EXP:
                    num2 = output.top().get_value();
                    output.pop();
                    num1 = output.top().get_value();
                    output.pop();
                    output.push(IntObject(std::pow(num1, num2), std::to_string(num1 + num2)));
                    break;
            }
        }
    }
    return output.top().get_value();
}


