#include <iostream>
#include <vector>
#include <memory>

#include "config.h"

#include "spdlog/spdlog.h"

using std::vector;
using std::move;
using std::shared_ptr;

int main(int, char**) {

    config::LogManager::init();
    spdlog::get("logger")->info("Logger initialized with args {} {}", 1, 2);

    return 0;
}
