#include "streams/LFStream.h"

#include <algorithm>
#include <iostream>

LFStream::LFStream(Problem * problem): Stream(problem)
{

}

double LFStream::operator ()(const double uA, const double uB) const
{
	assert(!std::isnan   (uA));
	assert(!std::isinf   (uA));
	assert( std::isfinite(uA));

	assert(!std::isnan   (uB));
	assert(!std::isinf   (uB));
	assert( std::isfinite(uB));

	static int numberOfCalls = 0;
	if (numberOfCalls == 0)
	{
		std::cout << "LFStream works only if u-0min = 0, u-0max = 1"
		<< std::endl;
	}
	numberOfCalls ++;
		// поток в точке x(j+1/2)
		// uA = предельное значение слева, то есть значение в точке x(j)
		// uB = предельное значение справа, то есть значение в точке x(j+1)
	static double C;
	static double c;
	c = std::max(uA, uB);
//	C = abs(m_problem->fDerivative(c));
	C = abs(m_problem->fDerivative(1.0));
	return (m_problem->f(uA) + m_problem->f(uB) - C * (uB - uA)) * 0.5;
}

std::string LFStream::getName() const
{
	return "LFStream";
}
