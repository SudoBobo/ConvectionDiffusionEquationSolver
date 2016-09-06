#ifndef RUNGEKUTTASYSTEMSOLVER_H
#define RUNGEKUTTASYSTEMSOLVER_H

#include "SystemSolver.h"

class RungeKuttaSystemSolver: public SystemSolver
{
public:
	RungeKuttaSystemSolver(Limiter * limiter, Conditions * conditions,
						   SystemMaker * systemMaker);
	double * uNew(const int k, const int j,
						  const double * uPrev, const double * u,
						  const double * uNext) const;
};

#endif // RUNGEKUTTASYSTEMSOLVER_H
