#include <iostream>
#include "REPL.h"
#include <spdlog/spdlog.h>

int main() {
    spdlog::set_level(spdlog::level::off);
    REPL repl;
    repl.start();
    return 0;
}