#ifndef RUNGEKUTTASYSTEMSOLVER_H
#define RUNGEKUTTASYSTEMSOLVER_H

#include "SystemSolver.h"

class RungeKuttaSystemSolver: public SystemSolver
{
public:
	RungeKuttaSystemSolver(Limiter * limiter, Conditions * conditions,
						   SystemMaker * systemMaker);
	void calcNextState(const State & currentState, State & nextState) const;
//	Polynomial uNew(const Polynomial & uPrev, const Polynomial & u,
//						  const Polynomial & uNext) const;
};

#endif // RUNGEKUTTASYSTEMSOLVER_H
