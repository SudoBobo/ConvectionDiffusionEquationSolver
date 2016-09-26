#include <algorithm>

#include "streams/GodunovStream.h"

GodunovStream::GodunovStream(Problem * problem): Stream(problem)
{

}

double GodunovStream::operator ()(const double uA, const double uB) const
{
	assert(!std::isnan   (uA));
	assert(!std::isinf   (uA));
	assert( std::isfinite(uA));

	assert(!std::isnan   (uB));
	assert(!std::isinf   (uB));
	assert( std::isfinite(uB));

		// поток в точке x(j+1/2)
		// uA = предельное значение слева, то есть значение в точке x(j)
		// uB = предельное значение справа, то есть значение в точке x(j+1)
		if (uA <= uB)
				return std::min(m_problem->f(uA), m_problem->f(uB));
		else
				return std::max(m_problem->f(uA), m_problem->f(uB));
}

std::string GodunovStream::getName() const
{
	return "Godunov";
}
