#include "support/MyMath.h"
#include <cmath>
#include <iostream>
#include <assert.h>

double calcAvgValue(const double spatialStep,
				 const Polynomial &u)
{

	assert(!std::isnan   (u(0)));
	assert(!std::isinf   (u(0)));
	assert( std::isfinite(u(0)));

	assert(!std::isnan   (u(1)));
	assert(!std::isinf   (u(1)));
	assert( std::isfinite(u(1)));

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

	static int k;

	k = u.getOrder();
	switch(k)
	{
	case 0:
		return u(0);
	case 1:
		// works just fine, don't touch please
		return u(0) + (u(1) / (h * h)) *
		(xJnext * xJnext - xJprev * xJprev) -
		 (u(1) * 2.0 * xJ / h);
	}
	std::range_error("something went wrong in calculating average interval value");
	return 0;
}


double integral23(const int l, const double spatialStep,
				  const Polynomial & u)
{
	assert(!std::isnan   (u(0)));
	assert(!std::isinf   (u(0)));
	assert( std::isfinite(u(0)));

	assert(!std::isnan   (u(1)));
	assert(!std::isinf   (u(1)));
	assert( std::isfinite(u(1)));

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
	std::range_error("something went wrong in calculating integral 2.3");
	return 0;
}



double m (double a, double b)
{

	assert(!std::isnan   (a));
	assert(!std::isinf   (a));
	assert( std::isfinite(a));

	assert(!std::isnan   (b));
	assert(!std::isinf   (b));
	assert( std::isfinite(b));

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
	assert(!std::isnan   (a));
	assert(!std::isinf   (a));
	assert( std::isfinite(a));

	assert(!std::isnan   (b));
	assert(!std::isinf   (b));
	assert( std::isfinite(b));

	assert(!std::isnan   (c));
	assert(!std::isinf   (c));
	assert( std::isfinite(c));


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

	assert(!std::isnan   (a));
	assert(!std::isinf   (a));
	assert( std::isfinite(a));

	assert(!std::isnan   (b));
	assert(!std::isinf   (b));
	assert( std::isfinite(b));

	assert(!std::isnan   (c));
	assert(!std::isinf   (c));
	assert( std::isfinite(c));

	assert(!std::isnan   (d));
	assert(!std::isinf   (d));
	assert( std::isfinite(d));


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

	assert(!std::isnan   (a));
	assert(!std::isinf   (a));
	assert( std::isfinite(a));

	assert(!std::isnan   (b));
	assert(!std::isinf   (b));
	assert( std::isfinite(b));

	assert(!std::isnan   (c));
	assert(!std::isinf   (c));
	assert( std::isfinite(c));


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
	assert(!std::isnan   (val));
	assert(!std::isinf   (val));
	assert( std::isfinite(val));

	return ((0.0 < val) - (val < 0.0));
}


double triangle (double lN1, double lN2, double x, double t)
{
	assert(!std::isnan   (lN1));
	assert(!std::isinf   (lN1));
	assert( std::isfinite(lN1));

	assert(!std::isnan   (lN2));
	assert(!std::isinf   (lN2));
	assert( std::isfinite(lN2));

	assert(!std::isnan   (x));
	assert(!std::isinf   (x));
	assert( std::isfinite(x));

	assert(!std::isnan   (t));
	assert(!std::isinf   (t));
	assert( std::isfinite(t));

		if (t == 0)
		{
				if ((lN1 <= x) && (x <= (0.5 * (lN1 + lN2))))
						return (2 * (x - lN1)) / (lN2 - lN1 + 2.0);

				if (((0.5 * (lN1 + lN2)) < x) && ( x <= lN2))
						return (2 * (lN2 - x)) / (lN2 - lN1 - 2.0);

				if (!((lN1 <= x) && (x <= lN2)))
						return 0.0;

		}

		if (( 0.0 < t) && (t <= (0.5 * (lN2 - lN1))))
		{
				if ((lN1 <= x) && (x <= (0.5 * (lN1 + lN2) + t)))
						return (2 * (x - lN1)) / (lN2 - lN1 + 2.0 * t);

				if (((0.5 * (lN1 + lN2) + t) < x) && ( x <= lN2))
						return (2 * (lN2 - x)) / (lN2 - lN1 - 2.0 * t);

				if (!((lN1 <= x) && (x <= lN2)))
						return 0.0;
		}

		if (( 0.5 * (lN2 - lN1)) < t)
		{
				if ((lN1 <= x) && (x <= sqrt(0.5 * (lN2 - lN1) * (lN2 - lN1 + 2.0 * t))))
						return ((2.0 * (x - lN1))/(lN2 - lN1 + 2.0 * t));
				return 0.0;
		}
		//throw std::range_error("triangle error");
}

double u0Triangle(double x, int l, double h, double lN1, double lN2)
{
	if (lN1 == 0.0)
	{

	}
	else
	{
		assert(!std::isnan   (lN1));
		assert(!std::isinf   (lN1));
		assert( std::isfinite(lN1));
	}

	assert(!std::isnan   (lN2));
	assert(!std::isinf   (lN2));
	assert( std::isfinite(lN2));

	assert(!std::isnan   (x));
	assert(!std::isinf   (x));
	assert( std::isfinite(x));

	assert(!std::isnan   (l));
	assert(!std::isinf   (l));
	assert( std::isfinite(l));
	assert((0 <= l) && (l <= 20));


	assert(!std::isnan   (h));
	assert(!std::isinf   (h));
	assert( std::isfinite(h));

		static double intervalN1;
		static double intervalN2;

		intervalN1 = 0.0;
		intervalN2 = 0.0;

		static double middle = 0.5 * (lN2 +lN1);

		static double xPrev;
		static double xNext;

		xPrev = x - h;
		xNext = x + h;
		assert((l == 0) || (l == 1));
		switch (l)
		{
		case 0:

				if ((lN1 <= xPrev) && (xNext <= middle))
				{
						intervalN1 = ((2.0) / (h * (lN2 - lN1))) *
												 (
												 xNext * (xNext / 2.0 - lN1) -
												 xPrev * (xPrev / 2.0 - lN1)
												 );
						intervalN2 = 0.0;
				break;
				}

				if ((xPrev <= middle) && (middle <= xNext))
				{
						intervalN1 = ((2.0) / (h * (lN2 - lN1))) *
												 (
												 lN1 * (lN1 / 2.0 - lN1) -
												 xPrev * (xPrev / 2.0 - lN1)
												 );
						intervalN2 = ((2.0) / (h * (lN2 - lN1))) *
												 (
												 xNext * (lN2 - xNext / 2.0) -
												 lN1 * (lN2 - lN1 / 2.0)
												 );
						break;
				}

				if ((middle <= xPrev) && (xNext <= lN2))
				{
						intervalN1 = 0.0;
						intervalN2 = ((2.0) / (h * (lN2 - lN1))) *
												 (
												 xNext * (lN2 - xNext / 2.0) -
												 xPrev * (lN2 - xPrev / 2.0)
												 );
						break;
				}

				if ((xPrev <= lN2) && (lN2 < xNext))
				{
						intervalN1 = 0.0;
						intervalN2 = ((2.0) / (h * (lN2 - lN1))) *
												 (
												 lN2 * (lN2 - lN2 / 2.0) -
												 xPrev * (lN2 - xPrev / 2.0)
												 );
						break;
				}

				if (lN2 < xPrev)
				{
						intervalN1 = 0.0;
						intervalN2 = 0.0;
						break;
				}

		case 1:
				if ((lN1 <= xPrev) && (xNext <= middle))
				{
						intervalN1 = (2.0 * (6.0) / (h * (lN2 - lN1))) *
												 (
												 (xNext * xNext) * (xNext / 3.0 - lN1 / 2.0) -
												 (xPrev * xPrev) * (xPrev / 3.0 - lN1 / 2.0)
												 );
						intervalN2 = 0.0;
				break;
				}

				if ((xPrev <= middle) && (middle <= xNext))
				{
						intervalN1 = (2.0 * (6.0) / (h * (lN2 - lN1))) *
												 (
												 (lN2 * lN2) * (lN2 / 3.0 - lN1 / 2.0) -
												 (xPrev * xPrev) * (xPrev / 3.0 - lN1 / 2.0)
												 );
						intervalN2 = (2.0 * (6.0) / (h * (lN2 - lN1))) *
												 (
												 (xNext * xNext) * (lN2 / 2.0 - xNext / 3.0) -
												 (lN1 * lN1) * (lN2 / 2.0 - lN1 / 3.0)
												 );
						break;
				}

				if ((middle <= xPrev) && (xNext <= lN2))
				{
						intervalN1 = 0.0;
						intervalN2 = (2.0 * (6.0) / (h * (lN2 - lN1))) *
												 (
												 (xNext * xNext) * (lN2 / 2.0 - xNext / 3.0) -
												 (xPrev * xPrev) * (lN2 / 2.0 - xPrev / 3.0)
												 );
						break;
				}

				if ((xPrev <= lN2) && (lN2 < xNext))
				{
						intervalN1 = 0.0;
						intervalN2 = (2.0 * (6.0) / (h * (lN2 - lN1))) *
												 (
												 (lN2 * lN2) * (lN2 / 2.0 - lN2 / 3.0) -
												 (xPrev * xPrev) * (lN2 / 2.0 - xPrev / 3.0)
												 );
						break;
				}

				if (lN2 < xPrev)
				{
						intervalN1 = 0.0;
						intervalN2 = 0.0;
						break;
				}
		}

		assert(!std::isnan   (intervalN1));
		assert(!std::isinf   (intervalN1));
		assert( std::isfinite(intervalN1));

		assert(!std::isnan   (intervalN2));
		assert(!std::isinf   (intervalN2));
		assert( std::isfinite(intervalN2));

		return intervalN1 + intervalN2;
}
