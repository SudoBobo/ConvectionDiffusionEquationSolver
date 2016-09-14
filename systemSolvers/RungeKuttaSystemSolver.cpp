#include "RungeKuttaSystemSolver.h"

RungeKuttaSystemSolver::RungeKuttaSystemSolver(Limiter * limiter,
											   Conditions * conditions,
											   SystemMaker * systemMaker)
	:SystemSolver(limiter, conditions, systemMaker)
{

}

//Polynomial RungeKuttaSystemSolver::uNew(const Polynomial & uPrev, const Polynomial & u,
//					  const Polynomial & uNext) const
//{
//	return u;
//}

void RungeKuttaSystemSolver::calcNextState(const State & currentState,
									   State & nextState) const
{
	nextState = currentState;
}

std::string RungeKuttaSystemSolver::getName() const
{
	return "RungeKutta";
}
