//
// Created by CoolBassist on 25/09/2022.
//

#include "Error.h"

Error::Error(error_type type, std::string token, int position){
    this->type = type;
    this->token = token;
    this->position = position;
}

std::string Error::get_error() {
    std::string msg = "";

    switch(type){
        case UNEXPECTED_TOKEN:
            msg += "Unexpected token";
            break;
        case UNKNOWN_IDENTIFIER:
            msg += "Unknown identifier";
            break;
        case SYNTAX_ERROR:
            msg += "Syntax Error";
            break;
        case EXPECTED_TOKEN:
            return "Reached EOL. expected an expression.";   // returns early here.
        case MISSING_OPEN_BRACKET:
            msg += "Missing opening bracket";
            break;
        case MISSING_CLOSING_BRACKET:
            msg += "Missing closing bracket";
            break;
        case NO_EXPRESSION:
            return "No expression found. Did you forget to type something in?\n"; // returns early here.
        case DIV_BY_0:
            return "Division by 0"; // returns early here
    }

    msg += ": \"";
    msg += token;
    msg += "\"";

    return msg;
}

int Error::get_position() {
    return position;
}
