#ifndef GALERKINSYSTEMMAKER_H
#define GALERKINSYSTEMMAKER_H

#include "systemMakers/SystemMaker.h"

class GalerkinSystemMaker: public SystemMaker
{
public:
	GalerkinSystemMaker(Problem * problem, Conditions * conditions,
						Stream * stream, const int k);
	GalerkinSystemMaker(Problem *problem, Conditions *conditions, const int k);
	double dU(const int l, const Polynomial &  uPrev,
						  const Polynomial & u,
						  const Polynomial & uNext) const;
	std::string getName() const;
};

#endif // GALERKINSYSTEMMAKER_H
