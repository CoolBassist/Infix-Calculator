//
// Created by errey on 05/09/2022.
//

#include <iostream>
#include "Evaluator.h"

Evaluator::Evaluator(std::vector<Object> objects) {
    this->objects = objects;
}

int Evaluator::get_result() {
    for(Object obj: objects){
        switch (obj.token_type) {
            case INT:
                output.push(obj);
                break;
            case OP:
                int num2 = output.top().value;
                output.pop();
                int num1 = output.top().value;
                output.pop();

                if(!obj.literal.compare("+")){
                    output.push(Object(INT, num1+num2, std::to_string(num1+num2)));
                }else if(!obj.literal.compare("-")){
                    output.push(Object(INT, num1-num2, std::to_string(num1-num2)));
                }else if(!obj.literal.compare("*")){
                    output.push(Object(INT, num1*num2, std::to_string(num1*num2)));;
                }else if(!obj.literal.compare("/")){
                    output.push(Object(INT, num1/num2, std::to_string(num1/num2)));
                }

                break;
        }
    }

    return output.top().value;
}


