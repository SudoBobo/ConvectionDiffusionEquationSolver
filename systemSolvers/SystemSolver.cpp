#include "SystemSolver.h"

SystemSolver::SystemSolver(Limiter *limiter, Conditions *conditions,
						   SystemMaker *systemMaker)
{
	m_limiter = limiter;
	m_conditions = conditions;
	m_systemMaker = systemMaker;
}

