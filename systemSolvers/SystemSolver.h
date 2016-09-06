#ifndef SYSTEMSOLVER_H
#define SYSTEMSOLVER_H

#include "limiters/Limiter.h"
#include "support/Conditions.h"
#include "systemMakers/SystemMaker.h"

class SystemSolver
{
public:
	SystemSolver(Limiter * limiter, Conditions * conditions, SystemMaker * systemMaker);
	virtual double * uNew(const int k, const int j,
						  const double * uPrev, const double * u,
						  const double * uNext) const = 0;
protected:
	Limiter * m_limiter;
	Conditions * m_conditions;
	SystemMaker * m_systemMaker;

};

#endif // SYSTEMSOLVER_H
