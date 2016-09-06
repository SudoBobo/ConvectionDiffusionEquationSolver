#include "GalerkinSystemMaker.h"

#include <cmath>

#include "MyMath.h"

GalerkinSystemMaker::GalerkinSystemMaker(Problem * problem,
										 Conditions * conditions, Stream *stream,
										 const int k)
	:SystemMaker(problem, conditions, stream, k)
{

}

double GalerkinSystemMaker::dU(const int l, const int j,
							   const double * uPrev, const double * u,
							   const double * uNext) const
{
	static double uValue;
	static double uPrevValue;
	static double uNextValue;

	static const double spatialStep = m_conditions->getSpatialStep();

	uValue = calcAvgValue(m_k, j, spatialStep, u);
	uPrevValue =  calcAvgValue(m_k, j - 1, spatialStep, uPrev);
	uNextValue =  calcAvgValue(m_k, j + 1, spatialStep, uNext);

	double integral = integral23(m_k, j, l, spatialStep, u);

	return ((2.0 * l + 1.0) / m_conditions->getSpatialStep()) *
					 (
					   (integral) - (m_stream->operator ()(uValue, uNextValue) -
							std::pow(-1.0, l) *
							m_stream->operator ()(uPrevValue, uNextValue))
					 );
}
