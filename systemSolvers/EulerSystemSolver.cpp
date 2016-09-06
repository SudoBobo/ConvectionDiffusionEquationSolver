#include "EulerSystemSolver.h"

EulerSystemSolver::RungeKuttaSystemSolver(Limiter * limiter,
											   Conditions * conditions,
											   SystemMaker * systemMaker)
	:SystemSolver(limiter, conditions, systemMaker)
{

}

double * EulerSystemSolver::uNew(const int k, const int j,
					  const double * uPrev, const double * u,
					  const double * uNext) const
{
	static double uTemp[k + 1];
	static double uNew[k + 1];

	for (int l = 0; l < k + 1; l++)
	{
		uTemp[l] = m_conditions->getTimeStep() *
				   SystemMaker.dU(l, j, uPrev, u, uNext);

	}
	return nullptr;
}
