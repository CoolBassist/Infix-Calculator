//
// Created by CoolBassist on 05/09/2022.
//

#include <iostream>
#include "Evaluator.h"
#include <cmath>

Evaluator::Evaluator(std::vector<Object> objects) {
    this->objects = objects;
}

int Evaluator::get_result() {
    int num1, num2, trig_value;
    for(Object obj: objects){
        switch (obj.token_type) {
            case INT:
                output.push(obj);
                break;
            case ADD:
                num2 = output.top().value;
                output.pop();
                num1 = output.top().value;
                output.pop();
                output.push(Object(INT, num1+num2, std::to_string(num1+num2)));
                break;

            case SUB:
                num2 = output.top().value;
                output.pop();
                num1 = output.top().value;
                output.pop();
                output.push(Object(INT, num1-num2, std::to_string(num1-num2)));
                break;

            case MULT:
                num2 = output.top().value;
                output.pop();
                num1 = output.top().value;
                output.pop();
                output.push(Object(INT, num1*num2, std::to_string(num1*num2)));
                break;

            case DIV:
                num2 = output.top().value;
                output.pop();
                num1 = output.top().value;
                output.pop();
                output.push(Object(INT, num1/num2, std::to_string(num1/num2)));
                break;
            case EXP:
                num2 = output.top().value;
                output.pop();
                num1 = output.top().value;
                output.pop();
                output.push(Object(INT, std::pow(num1, num2), std::to_string(num1+num2)));
                break;
            case SIN:
                num1 = output.top().value;
                trig_value = 180/(std::sin(num1)*M_PI);
                output.push(Object(INT, trig_value , std::to_string(trig_value)));
                break;
            case COS:
                num1 = output.top().value;
                trig_value = 180/(std::sin(num1)*M_PI);
                output.push(Object(INT, trig_value , std::to_string(trig_value)));
                break;
            case TAN:
                num1 = output.top().value;
                trig_value = 180/(std::sin(num1)*M_PI);
                output.push(Object(INT, trig_value , std::to_string(trig_value)));
                break;
        }
    }

    return output.top().value;
}


