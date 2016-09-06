#ifndef LIMITERN3BM_H
#define LIMITERN3BM_H

#include "limiters/Limiter.h"

class LimiterN3BM
{
public:
	LimiterN3BM(Conditions * conditions, const int k);
	Polynomial limit(const Polynomial & uPrev, const Polynomial & u,
						 const Polynomial & uNext) const;
};

#endif // LIMITERN3BM_H
