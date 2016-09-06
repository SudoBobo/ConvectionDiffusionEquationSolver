#ifndef LIMITERN2_H
#define LIMITERN2_H

#include "limiters/Limiter.h"


class LimiterN2: public Limiter
{
public:
	LimiterN2(Conditions * conditions, const int k);
	double * limit(const double * uPrev, const double * u,
					 const double * uNext, const int jPrev, const int j, const int jNext) const;
};

#endif // LIMITERN2_H
