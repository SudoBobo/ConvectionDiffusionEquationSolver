#include <exception>
#include <stdexcept>
#include <assert.h>
#include <cmath>

#include "limiters/MUSCLLimiter.h"
#include "support/MyMath.h"

MUSCLLimiter::MUSCLLimiter(Conditions *conditions, const int k):
	Limiter(conditions, k)
{

	if (m_k != 1)
	{
	if (m_k == 0)
	{

	}
	else
	throw std::range_error("MUSCL limiter is only for the linear aproximation");
	}
}

std::string MUSCLLimiter::getName() const
{
	return "MUSCL";
}


Polynomial MUSCLLimiter::limit(const Polynomial & uPrev, const Polynomial & u,
											  const Polynomial & uNext) const
{
	if (m_k == 1)
	{
	static const double k = 1;
	static double h;
	h = m_conditions->getSpatialStep();
	assert(std::isfinite(h));

	static double j;
	static double xJ;
	j = u.getJ();
//	xJ = j * h;
	xJ = j * h + h * 0.5;

	//average  values (see limiters definition in article)
	static double avgValuePrev;
	static double avgValue;
	static double avgValueNext;

	avgValuePrev = calcAvgValue(h, uPrev);
	avgValue = calcAvgValue(h, u);
	avgValueNext = calcAvgValue(h, uNext);

	auto test = avgValue;
	assert(!std::isnan(test));
	assert(!std::isinf(test));
	assert(std::isfinite(test));

	test = avgValuePrev;
	assert(!std::isnan(test));
	assert(!std::isinf(test));
	assert(std::isfinite(test));

	test = avgValueNext;
	assert(!std::isnan(test));
	assert(!std::isinf(test));
	assert(std::isfinite(test));

	Polynomial uNew(j, k);

	static double b;
	static double c;

	b = (avgValueNext - avgValue) / h;
	c = (avgValue - avgValuePrev) / h;

	assert(!std::isnan(b));
	assert(!std::isinf(b));
	assert(std::isfinite(b));

	assert(!std::isnan(c));
	assert(!std::isinf(c));
	assert(std::isfinite(c));

	// just like in the article
	uNew(0) = avgValue - xJ * m(u(1), b, c);
	uNew(1) = m(u(1), b, c);

//	uNew(0) = u(0);
//	uNew(1) = u(1);

	assert(!std::isnan(uNew(0)));
	assert(!std::isinf(uNew(0)));
	assert(std::isfinite(uNew(0)));

	assert(!std::isnan(uNew(1)));
	assert(!std::isinf(uNew(1)));
	assert(std::isfinite(uNew(1)));

	return uNew;
	}

	if (m_k == 0)
	{
		return u;
	}
}
