// cppimport
#include <pybind11/pybind11.h>

#include "fnv1a.hxx"
#include "bloomfilter.hxx"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(_cpp, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------
        .. currentmodule:: pyblossom
        .. autosummary::
           :toctree: _generate
    )pbdoc";

    m.def("fnv1a", py::overload_cast<const char*>(&fnv1a));
    m.def("fnv1a", py::overload_cast<const char*, char>(&fnv1a));

    py::class_<BloomFilter>(m, "BloomFilter")
        .def(py::init<uint16_t, uint16_t>())
        .def("add", &BloomFilter::add)
        .def("mightContain", &BloomFilter::mightContain);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}

/*
<%
setup_pybind11(cfg)
%>
*/