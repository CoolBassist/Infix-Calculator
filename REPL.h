//
// Created by CoolBassist on 06/09/2022.
//

#ifndef INFIXCALC_REPL_H
#define INFIXCALC_REPL_H


#include "Lexer.h"
#include "ShuntYard.h"
#include "Evaluator.h"

class REPL {
private:
    bool debug = false;
    Lexer *l;
    ShuntYard *sy;
    Evaluator *e;
    std::string prefix = ">>>";
    void test();
public:
    void start();
};

#endif //INFIXCALC_REPL_H
