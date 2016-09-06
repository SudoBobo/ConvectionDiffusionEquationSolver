#include "Problem.h"

Problem::Problem()
{

}

double Problem::f(const double u) const
{
	return (u * u) / 2.0;
}

double Problem::fDerivative(const double u) const
{
return u;
}
