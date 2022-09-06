#include <iostream>
#include <map>
#include "Lexer.h"
#include "ShuntYard.h"
#include "Evaluator.h"


void test(){
    std::map<std::string, int> tests {{"3-(2+1)", 0}, {"2+2", 4}, {"((((((1+1)+1)+1)+1)+1)+1)", 7}, {"1*5", 5}, {"2*7+2", 16}, {"(3+4)*(4/2)", 14}, {"2 * 54 + 2 * (7 + 5) + 4/2", 134}};
    int i = 1;
    for(auto test: tests){
        Lexer l(test.first);
        std::vector<Token> tokens = l.get_tokens();
        ShuntYard sy(tokens);
        std::vector<Object> objects = sy.to_infix();
        Evaluator e(objects);
        int result = e.get_result();
        if(result != test.second){
            std::cout << "test #" << i << " failed. Got " << result << " expected " << test.second << "\n";
            std::cout << "Tokens: ";

            for(Token t: tokens){
                std::cout << "{" << t.get_type() << " '" << t.get_literal() << "'}, ";
            }

            std::cout << "Objects: ";

            for(Object obj: objects){
                std::cout << "{" << obj.literal << "}, ";
            }

        }else{
            std::cout << "test #" << i << " passed.\n";
        }
        i++;
    }
}

int main() {
    //std::string input = "2 * 54 + 2 * (7 + 5) + 4/2";
    std::string input = "-2+3-(-3--4)";
    //std::string input = "3-(2+1)";

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
        std::cout << "{";
        switch (t.get_type()){
            case ADD:
                std::cout << "ADD"; break;
            case SUB:
                std::cout << "SUB"; break;
            case DIV:
                std::cout << "DIV"; break;
            case MULT:
                std::cout << "MUL"; break;
            case LPAREN:
                std::cout << "LPA"; break;
            case RPAREN:
                std::cout << "RPA"; break;
            case INT:
                std::cout << "INT"; break;
        }

        std::cout << ", '" << t.get_literal() << "'}, ";
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

    test();

    return 0;
}



