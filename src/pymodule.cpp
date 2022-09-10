#include <pybind11/pybind11.h>

#include "Application.h"

namespace py = pybind11;

PYBIND11_MODULE(_emblem, m)
{
    Emblem::modularize_application(m);

    m.attr("__version__") = "dev";
}