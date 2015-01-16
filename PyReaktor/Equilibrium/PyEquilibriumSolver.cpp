// Reaktor is a C++ library for computational reaction modelling.
//
// Copyright (C) 2014 Allan Leal
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "PyEquilibriumSolver.hpp"

// Boost includes
#include <boost/python.hpp>
namespace py = boost::python;

// Reaktor includes
#include <Reaktor/Equilibrium/EquilibriumOptions.hpp>
#include <Reaktor/Equilibrium/EquilibriumProblem.hpp>
#include <Reaktor/Equilibrium/EquilibriumResult.hpp>
#include <Reaktor/Equilibrium/EquilibriumSolver.hpp>
#include <Reaktor/Equilibrium/EquilibriumState.hpp>

namespace Reaktor {

auto export_EquilibriumSolver() -> void
{
    using ftype1 = EquilibriumResult(EquilibriumSolver::*)(const EquilibriumProblem&, EquilibriumState&);
    using ftype2 = EquilibriumResult(EquilibriumSolver::*)(const EquilibriumProblem&, EquilibriumState&, const EquilibriumOptions&);

    py::class_<EquilibriumSolver>("EquilibriumSolver")
        .def("approximate", static_cast<ftype1>(&EquilibriumSolver::approximate))
        .def("approximate", static_cast<ftype2>(&EquilibriumSolver::approximate))
        .def("solve", static_cast<ftype1>(&EquilibriumSolver::solve))
        .def("solve", static_cast<ftype2>(&EquilibriumSolver::solve))
        ;
}

} // namespace Reaktor
