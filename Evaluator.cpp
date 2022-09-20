//
// Created by CoolBassist on 05/09/2022.
//
#include "Evaluator.h"
#include <cmath>
#include <variant>
#include <iostream>

Evaluator::Evaluator(std::vector<std::variant<IntObject, OpObject, RealObject>> objects) {
    this->objects = objects;
}

double Evaluator::get_result() {
    double num1, num2;
    bool num2_int, num1_int;
    for (std::variant<IntObject, OpObject, RealObject> obj: objects) {
        if (std::holds_alternative<IntObject>(obj)) {
            output.push(std::get<IntObject>(obj));
        } else if (std::holds_alternative<RealObject>(obj)) {
            output.push(std::get<RealObject>(obj));
        } else {
            switch (std::get<OpObject>(obj).get_type()) {
                case ADD:
                    num2_int = std::holds_alternative<IntObject>(output.top());
                    if (num2_int) {
                        num2 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num2 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();
                    num1_int = std::holds_alternative<IntObject>(output.top());
                    if (num1_int) {
                        num1 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num1 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();

                    if(num1_int && num2_int){
                        output.push(IntObject(num1 + num2, std::to_string(num1 + num2)));
                    }else{
                        output.push(RealObject(num1 + num2, std::to_string(num1 + num2)));
                    }

                    break;

                case SUB:
                    num2_int = std::holds_alternative<IntObject>(output.top());
                    if (num2_int) {
                        num2 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num2 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();
                    num1_int = std::holds_alternative<IntObject>(output.top());
                    if (num1_int) {
                        num1 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num1 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();
                    if(num1_int && num2_int){
                        output.push(IntObject(num1 - num2, std::to_string(num1 + num2)));
                    }else{
                        output.push(RealObject(num1 - num2, std::to_string(num1 + num2)));
                    }
                    break;

                case MULT:
                    num2_int = std::holds_alternative<IntObject>(output.top());
                    if (num2_int) {
                        num2 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num2 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();
                    num1_int = std::holds_alternative<IntObject>(output.top());
                    if (num1_int) {
                        num1 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num1 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();
                    if(num1_int && num2_int){
                        output.push(IntObject(num1 * num2, std::to_string(num1 + num2)));
                    }else{
                        output.push(RealObject(num1 * num2, std::to_string(num1 + num2)));
                    }
                    break;

                case DIV:
                    num2_int = std::holds_alternative<IntObject>(output.top());
                    if (num2_int) {
                        num2 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num2 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();
                    num1_int = std::holds_alternative<IntObject>(output.top());
                    if (num1_int) {
                        num1 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num1 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();
                    output.push(RealObject((num1*1.0) / num2, std::to_string(num1 + num2)));
                    break;

                case EXP:
                    num2_int = std::holds_alternative<IntObject>(output.top());
                    if (num2_int) {
                        num2 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num2 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();
                    num1_int = std::holds_alternative<IntObject>(output.top());
                    if (num1_int) {
                        num1 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num1 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();
                    if(num1_int && num2_int){
                        output.push(IntObject(std::pow(num1, num2), std::to_string(num1 + num2)));
                    }else{
                        output.push(RealObject(std::pow(num1, num2), std::to_string(num1 + num2)));
                    }
                    break;

                case SIN:
                    num1_int = std::holds_alternative<IntObject>(output.top());
                    if (num1_int) {
                        num1 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num1 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();

                    output.push(RealObject(std::sin((M_PI/180)*num1), std::to_string(std::sin(M_PI/180)*num1)));
                    break;

                case COS:
                    num1_int = std::holds_alternative<IntObject>(output.top());
                    if (num1_int) {
                        num1 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num1 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();

                    output.push(RealObject(std::cos((M_PI/180)*num1), std::to_string(std::cos(M_PI/180)*num1)));
                    break;

                case TAN:
                    num1_int = std::holds_alternative<IntObject>(output.top());
                    if (num1_int) {
                        num1 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num1 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();

                    output.push(RealObject(std::tan((M_PI/180)*num1), std::to_string(std::tan(M_PI/180)*num1)));
                    break;

                case LOG:
                    num1_int = std::holds_alternative<IntObject>(output.top());
                    if (num1_int) {
                        num1 = std::get<IntObject>(output.top()).get_value();
                    } else {
                        num1 = std::get<RealObject>(output.top()).get_value();
                    }
                    output.pop();

                    output.push(RealObject(std::log10(num1), std::to_string(std::log10(num1))));
                    break;
            }
        }
    }

    if (std::holds_alternative<IntObject>(output.top())) {
        return std::get<IntObject>(output.top()).get_value();
    } else {
        return std::get<RealObject>(output.top()).get_value();
    }
}


