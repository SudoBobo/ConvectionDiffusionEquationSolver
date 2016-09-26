#include "systemMakers/GalerkinSystemMaker.h"

#include <cmath>

#include "support/MyMath.h"

GalerkinSystemMaker::GalerkinSystemMaker(Problem * problem,
										 Conditions * conditions, Stream *stream,
										 const int k)
	:SystemMaker(problem, conditions, stream, k)
{

}

GalerkinSystemMaker::GalerkinSystemMaker(Problem *problem,
										 Conditions *conditions, const int k)
	:SystemMaker(problem, conditions, k)
{

}

double GalerkinSystemMaker::dU(const int l, const Polynomial &  uPrev,
										 const Polynomial & u,
										 const Polynomial & uNext) const
{
	static double uValue;
	static double uPrevValue;
	static double uNextValue;

	static const double spatialStep = m_conditions->getSpatialStep();

	uValue = calcAvgValue(spatialStep, u);
	uPrevValue =  calcAvgValue(spatialStep, uPrev);
	uNextValue =  calcAvgValue(spatialStep, uNext);


	assert(!std::isnan(uValue));
	assert(!std::isinf(uValue));
	assert(std::isfinite(uValue));

	assert(!std::isnan(uPrevValue));
	assert(!std::isinf(uPrevValue));
	assert(std::isfinite(uPrevValue));

	assert(!std::isnan(uNextValue));
	assert(!std::isinf(uNextValue));
	assert(std::isfinite(uNextValue));

	static double integral;
	integral = integral23(l, spatialStep, u);

	assert(!std::isnan   (integral));
	assert(!std::isinf   (integral));
	assert( std::isfinite(integral));

	assert(!std::isnan   (std::pow(-1.0, l)));
	assert(!std::isinf   (std::pow(-1.0, l)));
	assert( std::isfinite(std::pow(-1.0, l)));

	return ((2.0 * l + 1.0) / m_conditions->getSpatialStep()) *
					 (
					   (integral) - (m_stream->operator ()(uValue, uNextValue) -
							std::pow(-1.0, l) *
							m_stream->operator ()(uPrevValue, uValue))
					 );
}

std::string GalerkinSystemMaker::getName() const
{
	return "Galerkin";
}
