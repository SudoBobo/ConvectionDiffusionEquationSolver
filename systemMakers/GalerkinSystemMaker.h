#ifndef GALERKINSYSTEMMAKER_H
#define GALERKINSYSTEMMAKER_H

#include "SystemMaker.h"

class GalerkinSystemMaker: public SystemMaker
{
public:
	GalerkinSystemMaker(Problem * problem, Conditions * conditions,
						Stream * stream, const int k);
	double dU(const int l, const int j,
			const double * uPrev, const double * u, const double * uNext) const;
};

#endif // GALERKINSYSTEMMAKER_H
