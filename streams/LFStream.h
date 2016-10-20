#ifndef LFSTREAM_H
#define LFSTREAM_H

#include <string>
#include "streams/Stream.h"
#include "streams/LFStream.h"

class LFStream : public Stream
{
public:
	LFStream(Problem * problem);
	double operator()(const double uA, const double uB) const;
	std::string getName() const;
};


#endif // LFSTREAM_H
