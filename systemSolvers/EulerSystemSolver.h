#ifndef EULERSYSTEMSOLVER_H
#define EULERSYSTEMSOLVER_H

#include "SystemSolver.h"

class EulerSystemSolver: public SystemSolver
{
	public:
		EulerSystemSolver(Limiter * limiter, Conditions * conditions,
							   SystemMaker * systemMaker);
		double * uNew(const int k, const int j,
							  const double * uPrev, const double * u,
							  const double * uNext) const;
};

#endif // EULERSYSTEMSOLVER_H
