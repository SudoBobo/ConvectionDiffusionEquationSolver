#include "GalerkinSystemMaker.h"

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

GalerkinSystemMaker::std::string name() const
{
	return m_name;
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

	static double integral;
	integral = integral23(l, spatialStep, u);

	return ((2.0 * l + 1.0) / m_conditions->getSpatialStep()) *
					 (
					   (integral) - (m_stream->operator ()(uValue, uNextValue) -
							std::pow(-1.0, l) *
							m_stream->operator ()(uPrevValue, uValue))
					 );
}
