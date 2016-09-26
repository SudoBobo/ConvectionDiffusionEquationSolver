#include "support/Problem.h"
#include <assert.h>
#include <cmath>

Problem::Problem()
{

}

double Problem::f(const double u) const
{
	assert(!std::isnan   (u));
	assert(!std::isinf   (u));
	assert( std::isfinite(u));
	return (u * u) / 2.0;
}

double Problem::fDerivative(const double u) const
{
	assert(!std::isnan   (u));
	assert(!std::isinf   (u));
	assert( std::isfinite(u));
	return u;
}
