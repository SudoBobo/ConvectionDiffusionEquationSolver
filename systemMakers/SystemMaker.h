#ifndef SYSTEMMAKER_H
#define SYSTEMMAKER_H

#include "support/Conditions.h"
#include "support/Problem.h"
#include "streams/Stream.h"

class SystemMaker
{
public:
	SystemMaker( Problem * problem, Conditions * conditions, Stream * stream,
				 const int k);
	virtual double dU(const int l, const int j,
			const double * uPrev, const double * u,
					  const double * uNext) const = 0;

protected:
	Conditions * m_conditions;
	Problem * m_problem;
	Stream * m_stream;
	int  m_k;
};

#endif // SYSTEMMAKER_H
