#ifndef SYSTEMSOLVER_H
#define SYSTEMSOLVER_H

#include "limiters/Limiter.h"
#include "support/Conditions.h"
#include "systemMakers/SystemMaker.h"
#include "support/Polynomial.h"
#include "support/State.h"

class SystemSolver
{
public:
	SystemSolver(Limiter * limiter, Conditions * conditions,
				 SystemMaker * systemMaker);
	SystemSolver(Conditions * conditions);
	virtual void calcNextState(const State & currentState, State & nextState) const = 0;
//	virtual Polynomial uNew(const Polynomial & uPrev, const Polynomial & u,
//						  const Polynomial & uNext) const = 0;
protected:
	Limiter * m_limiter;
	Conditions * m_conditions;
	SystemMaker * m_systemMaker;

};

#endif // SYSTEMSOLVER_H
