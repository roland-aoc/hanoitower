#define NONIUS_RUNNER
#include "include/nonius-1.1.2-release/nonius.h++"
#include "common_test.h"
#include "spdlog/spdlog.h"

#include <memory>
#include <utility>

#include "config.h"

using std::move;

NONIUS_BENCHMARK("IntToStringTest1000", [] {
    // IntToStringConversionTest(1000);
})
