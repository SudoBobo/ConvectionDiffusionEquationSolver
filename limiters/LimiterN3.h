#ifndef LIMITERN3_H
#define LIMITERN3_H

#include "limiters/Limiter.h"

class LimiterN3
{
public:
	LimiterN3(Conditions * conditions, const int k);
	double * limit(const double * uPrev, const double * u,
					 const double * uNext,  const int jPrev, const int j, const int jNext) const;
};

#endif // LIMITERN3_H
