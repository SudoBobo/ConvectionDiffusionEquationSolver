#ifndef LIMITERN3_H
#define LIMITERN3_H

#include "limiters/Limiter.h"

class LimiterN3
{
public:
	LimiterN3(Conditions * conditions, const int k);
	Polynomial limit(const Polynomial & uPrev, const Polynomial & u,
						 const Polynomial & uNext) const;
};

#endif // LIMITERN3_H
