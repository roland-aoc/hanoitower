#include "config.h"

namespace config {    
    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> LogManager::consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    std::vector<spdlog::sink_ptr> LogManager::sinks{ consoleSink };
    std::shared_ptr<spdlog::logger> LogManager::logger = std::make_shared<spdlog::logger>("logger", sinks.begin(), sinks.end());

    void LogManager::init() {
        
        config::LogManager::consoleSink->set_pattern("[%x %H:%M:%S.%F %z] [%^%l%$] [%@] [thread %t] %v");
        // config::LogManager::logger = 
        config::LogManager::logger->set_level(spdlog::level::debug);
        config::LogManager::logger->flush_on(spdlog::level::debug);
        spdlog::register_logger(logger);

        config::LogManager::logger->info("Initialize logger");
        // auto consoleLog = spdlog::stdout_color_mt("console");
        // consoleLog->debug("Welcome to spdlog! Use consoleLog for debug logging");
        // SPDLOG_INFO("Use macro for info logging");
        // return move(consoleLog);
    }

    std::shared_ptr<spdlog::logger> LogManager::getLogger() {
        return config::LogManager::logger;
    }

    void LogManager::shutdownLogging() {
        spdlog::shutdown();
    }
}