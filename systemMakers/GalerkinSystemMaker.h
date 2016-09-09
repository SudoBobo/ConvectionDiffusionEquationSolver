#ifndef GALERKINSYSTEMMAKER_H
#define GALERKINSYSTEMMAKER_H

#include "SystemMaker.h"

class GalerkinSystemMaker: public SystemMaker
{
public:
	GalerkinSystemMaker(Problem * problem, Conditions * conditions,
						Stream * stream, const int k);
	GalerkinSystemMaker(Problem *problem, Conditions *conditions, const int k);
	double dU(const int l, const Polynomial &  uPrev,
						  const Polynomial & u,
						  const Polynomial & uNext) const;
	std::string m_name() const;
private:
	static std::string name = "Galerkin";
};

#endif // GALERKINSYSTEMMAKER_H
