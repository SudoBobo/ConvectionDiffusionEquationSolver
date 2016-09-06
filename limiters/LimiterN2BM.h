#ifndef LIMITERN2BM_H
#define LIMITERN2BM_H

#include "limiters/Limiter.h"


class LimiterN2BM
{
public:
	LimiterN2BM(Conditions * conditions, const int k);
	double * limit(const double * uPrev, const double * u,
					 const double * uNext, const int jPrev, const int j, const int jNext) const;
};

#endif // LIMITERN2BM_H
