#include "Application.h"

#include "Log.h"

namespace Emblem
{

    Application::Application()
    {
        Emblem::Log::Init();
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (true)
            ;
    }

    void modularize_application(pybind11::module &m)
    {
        pybind11::class_<Application>(m, "Application")
            .def(pybind11::init<>())
            .def("run", &Application::Run);
    }
}