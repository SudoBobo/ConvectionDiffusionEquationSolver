#ifndef RUNGEKUTTASYSTEMSOLVER_H
#define RUNGEKUTTASYSTEMSOLVER_H

#include "systemSolvers/SystemSolver.h"

class RungeKuttaSystemSolver: public SystemSolver
{
public:
	RungeKuttaSystemSolver(Limiter * limiter, Conditions * conditions,
						   SystemMaker * systemMaker);
	void calcNextState(const State & currentState, State & nextState) const;
//	Polynomial uNew(const Polynomial & uPrev, const Polynomial & u,
//						  const Polynomial & uNext) const;
	std::string getName() const;

};

#endif // RUNGEKUTTASYSTEMSOLVER_H
