#pragma once

#include <pybind11/pybind11.h>

namespace Emblem
{

    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    void modularize_application(pybind11::module &m);
}
