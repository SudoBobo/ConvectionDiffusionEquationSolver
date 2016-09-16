#ifndef SYSTEMMAKER_H
#define SYSTEMMAKER_H

#include <string>

#include "support/Conditions.h"
#include "support/Problem.h"
#include "streams/Stream.h"
#include "support/Polynomial.h"

class SystemMaker
{
public:
	SystemMaker( Problem * problem, Conditions * conditions, Stream * stream,
				 const int k);
	SystemMaker(Problem * problem, Conditions * conditions, const int k);

	virtual double dU(const int l, const Polynomial &  uPrev,
					  const Polynomial & u,
					  const Polynomial & uNext) const = 0;
	virtual std::string getName() const = 0;

	void setStream(Stream * newStream);
	Stream * getStream ();
	int getK() const;

protected:
	Conditions * m_conditions;
	Problem * m_problem;
	Stream * m_stream;
	int  m_k;
};

#endif // SYSTEMMAKER_H
