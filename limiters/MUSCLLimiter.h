#ifndef MUSCLLIMITER_H
#define MUSCLLIMITER_H

#include "limiters/Limiter.h"
#include "limiters/MUSCLLimiter.h"

class MUSCLLimiter: public Limiter
{
public:
	MUSCLLimiter(Conditions * conditions, const int k);
	Polynomial limit(const Polynomial & uPrev, const Polynomial & u,
						 const Polynomial & uNext) const;
	std::string getName() const;
};

#endif // MUSCLLIMITER_H
