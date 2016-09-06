#ifndef MUSCLLIMITERBM_H
#define MUSCLLIMITERBM_H

#include "limiters/Limiter.h"


class MUSCLLimiterBM
{
public:
	MUSCLLimiterBM(Conditions * conditions, const int k);
	Polynomial limit(const Polynomial & uPrev, const Polynomial & u,
						 const Polynomial & uNext) const;
};

#endif // MUSCLLIMITERBM_H
