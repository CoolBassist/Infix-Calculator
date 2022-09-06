//
// Created by errey on 05/09/2022.
//

#include <iostream>
#include "Evaluator.h"

Evaluator::Evaluator(std::vector<Object> objects) {
    this->objects = objects;
}

int Evaluator::get_result() {
    int num1, num2;
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
                output.push(Object(INT, num1-num2, std::to_string(num1+num2)));
                break;

            case MULT:
                num2 = output.top().value;
                output.pop();
                num1 = output.top().value;
                output.pop();
                output.push(Object(INT, num1*num2, std::to_string(num1+num2)));
                break;

            case DIV:
                num2 = output.top().value;
                output.pop();
                num1 = output.top().value;
                output.pop();
                output.push(Object(INT, num1/num2, std::to_string(num1+num2)));
                break;
        }
    }

    return output.top().value;
}


