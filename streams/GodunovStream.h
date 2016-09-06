#ifndef GODUNOVSTREAM_H
#define GODUNOVSTREAM_H

#include "Stream.h"
//checked
class GodunovStream: public Stream
{
public:
	GodunovStream(Problem * problem);
	double operator()(const double uA, const double uB) const;

};

#endif // GODUNOVSTREAM_H
