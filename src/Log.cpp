#include "Log.h"

#include <string>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Emblem
{

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("EMBLEM");
        s_CoreLogger->set_level(spdlog::level::trace);
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }

    void trace(std::string &msg)
    {
        Emblem::Log::GetClientLogger()->trace(msg);
    }

    void info(std::string &msg)
    {
        Emblem::Log::GetClientLogger()->info(msg);
    }

    void warn(std::string &msg)
    {
        Emblem::Log::GetClientLogger()->warn(msg);
    }

    void error(std::string &msg)
    {
        Emblem::Log::GetClientLogger()->error(msg);
    }

    void modularize_log(pybind11::module &m)
    {
        m.def("log_trace", &trace);
        m.def("log_info", &info);
        m.def("log_warn", &warn);
        m.def("log_error", &error);
    }

}