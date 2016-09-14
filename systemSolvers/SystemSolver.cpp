#include "SystemSolver.h"

SystemSolver::SystemSolver(Limiter *limiter, Conditions *conditions,
						   SystemMaker *systemMaker)
{
	m_limiter = limiter;
	m_conditions = conditions;
	m_systemMaker = systemMaker;
}

SystemSolver::SystemSolver(Conditions *conditions)
{
	m_conditions = conditions;
}

void SystemSolver::setLimiter(Limiter *newLimiter)
{
	m_limiter = newLimiter;
}

void SystemSolver::setSystemMaker(SystemMaker *newSystemMaker)
{
	m_systemMaker = newSystemMaker;
}
