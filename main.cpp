#include <iostream>
#include "Lexer.h"
#include "ShuntYard.h"
#include "Evaluator.h"

int main() {
    std::string input = "2 * 54 + 2 * (7 + 5) + 4/2";

    std::cout << "Input: ";

    for(char c: input){
        if(c == ' '){
            continue;
        }

        std::cout << c;
    }

    std::cout << "\n\n";

    Lexer l(input);
    std::vector<Token> tokens = l.get_tokens();

    std::cout << "Tokenising...\nNumber of tokens: " << tokens.size() << "\n";

    std::cout << "Tokens: ";

    for(Token t: tokens){
        std::cout << "{" << t.get_type() << " '" << t.get_literal() << "'}, ";
    }

    std::cout << "\n\n";

    ShuntYard sy(tokens);
    std::vector<Object> objects = sy.to_infix();

    std::cout << "Converting to postfix...\nNumber of objects: " << objects.size() << "\n";

    std::cout << "Objects: ";

    for(Object obj: objects){
        std::cout << "{" << obj.literal << "}, ";
    }

    std::cout << "\n\n";

    Evaluator e(objects);

    std::cout << "Result: " << e.get_result() << "\n";

    return 0;
}

