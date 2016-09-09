#include "MyMath.h"
#include <cmath>
#include <iostream>

double calcAvgValue(const double spatialStep,
				 const Polynomial &u)
{
	//вычисление среднего значения по промежутку от j- 1/2 до j + 1/2
	// x(j), x(j+1/2), x(j-1/2)
	static double xJ;
	static double xJnext;
	static double xJprev;

	static int j;
	j = u.getJ();

	static double h;
	h = spatialStep;

	xJ = j * h;
	xJnext = xJ + 0.5 * h;
	xJprev = xJ - 0.5 * h;

	std::cout << "xJ = " << xJ << " xJnext = " << xJnext <<
				 " xJprev = " << xJprev << std::endl;
	static int k;

	k = u.getOrder();
	switch(k)
	{
	case 0:
		return u(0);
		std::cout << "fuck you!" << std::endl;
	case 1:
		// works just fine, don't touch please
		return u(0) + (u(1) / (h * h)) *
		(xJnext * xJnext - xJprev * xJprev) -
		 (u(1) * 2.0 * xJ / h);
	}
}


double integral23(const int l, const double spatialStep,
				  const Polynomial & u)
{
	static double xJ;
	static double xJnext;
	static double xJprev;

	static int j;
	j = u.getJ();

	static double h;
	h = spatialStep;

	xJ = j * h;
	xJnext = xJ + 0.5 * h;
	xJprev = xJ - 0.5 * h;

	static int k;
	k = u.getOrder();



	switch(k)
	{
	case 0:
		return 0.0;
	case 1:
		if (l == 0)
			return 0.0;
		if (l == 1)
		{
			static double a;
			static double b;
			a = u(0);
			b = u(1);
			return (a * a * h) + (4.0 * a * b / h) *
					((xJnext * xJnext - xJprev * xJprev) / 2.0 - xJ * h) +
					(4.0 * b * b / (h * h)) *
					((xJnext * xJnext * xJnext - xJprev * xJprev * xJprev)/3.0 -
					 xJ * (xJnext * xJnext - xJprev * xJprev) +
					 xJ * xJ * h);
		}
	}
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
double mForBMLimiters(double a, double b, double c)
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
