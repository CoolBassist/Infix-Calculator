//
// Created by CoolBassist on 06/09/2022.
//

#include <iostream>
#include <map>
#include "REPL.h"

void REPL::start() {
    while(true) {
        std::cout << prefix;
        std::string input;
        std::getline(std::cin ,input);
        if (!input.compare("exit")) {
            return;
        }else if(!input.compare("debug")){
            debug = !debug;
            continue;
        }else if(!input.compare("test")){
            test();
            continue;
        }

        l = new Lexer(input);

        std::vector<Token> tokens = l->get_tokens();

        if (tokens.size() == 0) {
            std::cout << "Error at tokenising stage.\n\n";
            continue;
        }

        if(debug){
            std::cout << "Number of tokens: " << tokens.size() << "\n";
            std::cout << "Tokens: ";
            std::string types[] {"INT", "ADD", "SUB", "MUL", "DIV", "EXP", "LPA", "RPA", "NEG", "SIN", "COS", "TAN"};
            for(Token t: tokens){
                std::cout << "{" << types[t.get_type()] << ", '" << t.get_literal() << "'}, ";
            }
            std::cout << "\n";
        }

        sy = new ShuntYard(tokens);

        std::vector<Object> objects;

        objects = sy->to_infix();

        if (objects.size() == 0) {
            std::cout << "Error at the shunt yard.\n\n";
            continue;
        }

        if(debug){
            std::cout << "Objects: ";
            for(Object obj: objects){
                std::cout << "{" << obj.literal << "}, ";
            }
            std::cout << "\n";
        }

        e = new Evaluator(objects);

        int result = e->get_result();

        std::cout << result << "\n";

        delete l;
        delete sy;
        delete e;
    }
}

void REPL::test(){
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