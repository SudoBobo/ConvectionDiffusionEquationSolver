#ifndef GODUNOVSTREAM_H
#define GODUNOVSTREAM_H

#include <string>
#include "streams/Stream.h"
//checked
class GodunovStream: public Stream
{
public:
	GodunovStream(Problem * problem);
	double operator()(const double uA, const double uB) const;
	std::string getName() const;


};

#endif // GODUNOVSTREAM_H
