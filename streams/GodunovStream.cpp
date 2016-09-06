#include <algorithm>

#include "GodunovStream.h"

GodunovStream::GodunovStream(Problem * problem): Stream(problem)
{

}

double GodunovStream::operator ()(const double uA, const double uB) const
{
		// поток в точке x(j+1/2)
		// uA = предельное значение слева, то есть значение в точке x(j)
		// uB = предельное значение справа, то есть значение в точке x(j+1)
		if (uA <= uB)
				return std::min(m_problem->f(uA), m_problem->f(uB));
		else
				return std::max(m_problem->f(uA), m_problem->f(uB));
}
