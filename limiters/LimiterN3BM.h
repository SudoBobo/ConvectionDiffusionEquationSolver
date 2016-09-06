#ifndef LIMITERN3BM_H
#define LIMITERN3BM_H

#include "limiters/Limiter.h"

class LimiterN3BM
{
public:
	LimiterN3BM(Conditions * conditions, const int k);
	double * limit(const double * uPrev, const double * u,
					 const double * uNext, const int jPrev, const int j, const int jNext) const;
};

#endif // LIMITERN3BM_H
