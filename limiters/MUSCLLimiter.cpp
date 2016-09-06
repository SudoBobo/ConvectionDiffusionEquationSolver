#include <exception>
#include <stdexcept>

#include "limiters/MUSCLLimiter.h"
#include "support/MyMath.h"

MUSCLLimiter::MUSCLLimiter(Conditions *conditions, const int k):
	Limiter(conditions, k)
{
	if (m_k != 1)
	{
	throw std::range_error("MUSCL limiter is only for the linear aproximation");
	}
}



Polynomial MUSCLLimiter::limit(const Polynomial & uPrev, const Polynomial & u,
											  const Polynomial & uNext) const
{

	static const double k = 1;
	static const double h = m_conditions->getSpatialStep();

	static double j;
	static double xJ;
	j = u.getJ();
	xJ = j * h;
	//average  values (see limiters definition in article)
	static double avgValuePrev;
	static double avgValue;
	static double avgValueNext;

	avgValuePrev = calcAvgValue(h, uPrev);
	avgValue = calcAvgValue(h, u);
	avgValueNext = calcAvgValue(h, uNext);

	Polynomial uNew(j, k);

	static double b;
	static double c;
	b = (avgValueNext - avgValue) / h;
	c = (avgValue - avgValuePrev) / h;

	// just like in the article
	uNew(0) = avgValue - xJ * m(u(1), b, c);
	uNew(1) = m(u(1), b, c);

	return uNew;
}
