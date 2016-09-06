#ifndef MUSCLLIMITERBM_H
#define MUSCLLIMITERBM_H

#include "limiters/Limiter.h"


class MUSCLLimiterBM
{
public:
	MUSCLLimiterBM(Conditions * conditions, const int k);
	double * limit(const double * uPrev, const double * u,
					 const double * uNext, const int jPrev, const int j, const int jNext) const;
};

#endif // MUSCLLIMITERBM_H
