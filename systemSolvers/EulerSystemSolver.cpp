#include "systemSolvers/EulerSystemSolver.h"
#include <assert.h>
#include <stdexcept>

EulerSystemSolver::EulerSystemSolver(Limiter * limiter,
											   Conditions * conditions,
											   SystemMaker * systemMaker)
	:SystemSolver(limiter, conditions, systemMaker)
{

}


EulerSystemSolver::EulerSystemSolver(Conditions * conditions)
	:SystemSolver(conditions)
{

}

void EulerSystemSolver::calcNextState(const State & currentState,
								 State & nextState) const
{
	assert(currentState.jSize() == 1);

	static Polynomial tempPoly;
	static Polynomial uPrev;
	static Polynomial u;
	static Polynomial uNext;

	static int iMax;
	iMax =  currentState.iSize() - 1;
	{
		// j = 0
		u = currentState(0,0);
		u = currentState(0, 0);
		uPrev = currentState(iMax, 0);
		uNext = currentState(1, 0);

		tempPoly = uNew (uPrev, u, uNext);
		nextState(0, 0, tempPoly);

		// j = N = iMax
		u = currentState(iMax, 0);
		uPrev = currentState(iMax - 1, 0);
		uNext = currentState(0, 0);

		tempPoly = uNew (uPrev, u, uNext);
		nextState(iMax, 0, tempPoly);

		// j from 1 to iMax - 1
		for (int i = 1; i <= iMax - 1; i++)
		{
			u = currentState(i, 0);
			uPrev = currentState(i - 1, 0);
			uNext = currentState(i + 1, 0);

			tempPoly = uNew (uPrev, u, uNext);
			nextState(i, 0, tempPoly);
		}
	}

}

Polynomial EulerSystemSolver::uNew(const Polynomial & uPrev, const Polynomial & u,
					  const Polynomial & uNext) const
{
	static double k;
	k = u.getOrder();

	Polynomial uTemp(u.getJ(), u.getOrder());

	for (int l = 0; l < k + 1; l++)
	{
		uTemp(l) = m_conditions->getTimeStep() *
				   m_systemMaker->dU(l, uPrev, u, uNext);
	}
	return m_limiter->limit(uPrev, uTemp, uNext);
}

std::string EulerSystemSolver::getName() const
{
	return "Euler";
}
