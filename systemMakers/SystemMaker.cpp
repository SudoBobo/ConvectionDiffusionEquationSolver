#include "systemMakers/SystemMaker.h"

SystemMaker::SystemMaker(Problem * problem, Conditions * conditions,
						 Stream * stream, const int k)
{
	m_problem = problem;
	m_conditions = conditions;
	m_stream = stream;
	m_k = k;
}


SystemMaker::SystemMaker(Problem * problem, Conditions * conditions, const int k)
{
	m_problem = problem;
	m_conditions = conditions;
	m_k = k;
}

void SystemMaker::setStream(Stream * newStream)
{
	m_stream = newStream;
}

int SystemMaker::getK() const
{
	return m_k;
}
