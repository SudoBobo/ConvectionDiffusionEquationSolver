#ifndef LIMITER_H
#define LIMITER_H

#include "support/Conditions.h"

class Limiter
{
public:
	Limiter(Conditions * conditions, const int k);
	virtual double * limit(const double * uPrev, const double * u,
					 const double * uNext) const = 0;
protected:
	Conditions * m_conditions;
	int m_k;
};

#endif // LIMITER_H
