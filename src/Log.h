#pragma once

#include <pybind11/pybind11.h>

#include <memory>
#include <spdlog/spdlog.h>

namespace Emblem
{

    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

    void trace(std::string &msg);
    void info(std::string &msg);
    void warn(std::string &msg);
    void error(std::string &msg);

    void modularize_log(pybind11::module &m);
}

// Core Log Macros
#define EB_CORE_TRACE(...) ::Emblem::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EB_CORE_INFO(...) ::Emblem::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EB_CORE_WARN(...) ::Emblem::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EB_CORE_ERROR(...) ::Emblem::Log::GetCoreLogger()->error(__VA_ARGS__)
