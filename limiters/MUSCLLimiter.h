#ifndef MUSCLLIMITER_H
#define MUSCLLIMITER_H

#include "limiters/Limiter.h"
#include "limiters/MUSCLLimiter.h"

class MUSCLLimiter: public Limiter
{
public:
	MUSCLLimiter(Conditions * conditions, const int k);
	double * limit(const double * uPrev, const double * u,
					 const double * uNext, const int jPrev, const int j, const int jNext) const;
};

#endif // MUSCLLIMITER_H
