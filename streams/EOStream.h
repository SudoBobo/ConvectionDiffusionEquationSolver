#ifndef EOSTREAM_H
#define EOSTREAM_H

#include <string>
#include "streams/Stream.h"

class EOStream : public Stream
{
public:
	EOStream(Problem * problem);
	double operator()(const double uA, const double uB) const;
	std::string getName() const;
};

#endif // EOSTREAM_H
