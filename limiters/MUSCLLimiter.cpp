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

	static const double h = m_conditions->getSpatialStep();
	//average  values (see limiters definition in article)
	static double vPrev;
	static double v;
	static double vNext;

//	vPrev = calcAvgValue(m_k, jPrev, h, uPrev);
//	v = calcAvgValue(m_k, j, h, u);
//	vNext = calcAvgValue(m_k, jNext, h, uPrev);

//	const int size = m_k + 1;
//	double limitedCoefs [size];
//	limited
	return u;

}
