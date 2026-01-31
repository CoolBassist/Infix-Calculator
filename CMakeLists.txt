cmake_minimum_required(VERSION 3.28)
project(InfixCalc)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
set(SPDLOG_FMT_EXTERNAL OFF CACHE BOOL "" FORCE)
FetchContent_Declare(spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.11.0
    GIT_SHALLOW ON)
FetchContent_MakeAvailable(spdlog)

add_executable(InfixCalc main.cpp Token.cpp Token.h Lexer.cpp Lexer.h ShuntYard.cpp ShuntYard.h Object.cpp Object.h Evaluator.cpp Evaluator.h REPL.cpp REPL.h Error.cpp Error.h)
target_link_libraries(InfixCalc PRIVATE spdlog::spdlog)