#include <pybind11/pybind11.h>

#include "Application.h"
#include "Log.h"

PYBIND11_MODULE(_emblem, m)
{
    Emblem::modularize_application(m);
    Emblem::modularize_log(m);

    m.attr("__version__") = "dev";
}

PYBIND11_MODULE(_log, m)
{
    Emblem::modularize_log(m);

    m.attr("__version__") = "dev";
}