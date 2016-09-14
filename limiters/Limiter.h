#ifndef LIMITER_H
#define LIMITER_H

#include <string>
#include "support/Polynomial.h"
#include "support/Conditions.h"

class Limiter
{
public:
	Limiter(Conditions * conditions, const int k);
	virtual  Polynomial limit(const Polynomial & uPrev, const Polynomial & u,
					 const Polynomial & uNext) const = 0;
	virtual std::string getName() const = 0;
protected:
	Conditions * m_conditions;
	int m_k;
};

#endif // LIMITER_H
