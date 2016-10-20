#include "streams/EOStream.h"

#include <algorithm>



EOStream::EOStream(Problem * problem): Stream(problem)
{

}

double EOStream::operator ()(const double uA, const double uB) const
{
	assert(!std::isnan   (uA));
	assert(!std::isinf   (uA));
	assert( std::isfinite(uA));

	assert(!std::isnan   (uB));
	assert(!std::isinf   (uB));
	assert( std::isfinite(uB));

		// поток в точке x(j+1/2)
		// uA = предельное значение слева, то есть значение в точке x(j)
		// uB = предельное значение справа, то есть значение в точке x(j+1)
		return 0.0;
}

std::string EOStream::getName() const
{
	return "EOStream";
}
