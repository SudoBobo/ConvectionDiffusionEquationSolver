#include "RungeKuttaSystemSolver.h"

RungeKuttaSystemSolver::RungeKuttaSystemSolver(Limiter * limiter,
											   Conditions * conditions,
											   SystemMaker * systemMaker)
	:SystemSolver(limiter, conditions, systemMaker)
{

}

double * RungeKuttaSystemSolver::uNew(const int k, const int j,
					  const double * uPrev, const double * u,
					  const double * uNext) const
{
	return nullptr;
}
