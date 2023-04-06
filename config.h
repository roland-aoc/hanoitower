#ifndef CONFIG_H
#define CONFIG_H

#include <memory>
#include <utility>
#include <vector>

//https://github.com/gabime/spdlog/wiki/3.-Custom-formatting
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"

using std::shared_ptr;
using std::move;

namespace config {
    class LogManager 
    {
    static std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> consoleSink;
    static std::vector<spdlog::sink_ptr> sinks;
    static std::shared_ptr<spdlog::logger> logger;

    public:
		static void init();
        static std::shared_ptr<spdlog::logger> getLogger();
        static void shutdownLogging();
    };
}

#endif