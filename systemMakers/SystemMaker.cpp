#include "SystemMaker.h"

SystemMaker::SystemMaker(Problem * problem, Conditions * conditions,
						 Stream * stream, const int k)
{
	m_problem = problem;
	m_conditions = conditions;
	m_stream = stream;
	m_k = k;
}
