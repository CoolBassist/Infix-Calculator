cmake_minimum_required(VERSION 3.23)
project(InfixCalc)

set(CMAKE_CXX_STANDARD 14)

add_executable(InfixCalc main.cpp Token.cpp Token.h Lexer.cpp Lexer.h ShuntYard.cpp ShuntYard.h Object.cpp Object.h Evaluator.cpp Evaluator.h REPL.cpp REPL.h)
