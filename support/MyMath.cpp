#include "MyMath.h"

double calcAvgValue(const double spatialStep,
				 const Polynomial &u)
{
	//calcValue
	//вычисление среднего значения по промежутку от j- 1/2 до j + 1/2
	// u_k = sum (u_j * phi_l)
	// int (u_k) dx from x(j-1/2) to x(j+1/2)
	// return int / h_x;
	return 0.0;
}


double integral23(const int k, const int j, const int l,
				  const double spatialStep,
				  const double * u)
{
	return 0.0;
}



double m (double a, double b)
{
	if (sgn(a) == sgn(b))
	{
		return sgn(a) * (std::min(std::abs(a), std::abs(b)));
	}
	else
	{
		return 0.0;
	}
}

double m(double a, double b, double c)
{
	if ((sgn(a) == sgn(b)) && (sgn(b) == sgn(c)))
	{
		return sgn(a) * std::min(std::min(std::abs(a), std::abs(b)),
								 std::abs(c));
	}
	else
	{
		return 0.0;
	}
}

double m(double a, double b, double c, double d)
{
	if ((sgn(a) == sgn(b)) && (sgn(b) == sgn(c)) && (sgn(c) == sgn(d)))
	{
		return sgn(a) * std::min(std::min(std::abs(a), std::abs(b)),
								 std::min(std::abs(c), std::abs(d)));
	}
	else
	{
		return 0.0;
	}
}



//??
double mTilda(double a, double b, double c)
{
	if ((sgn(a) == sgn(b)) && (sgn(b) == sgn(c)))
	{
		return sgn(a) * std::min(std::min(std::abs(a), std::abs(b)),
								 std::abs(c));
	}
	else
	{
		return 0.0;
	}
}

int sgn (double val)
{
	return ((0.0 < val) - (val < 0.0));
}
