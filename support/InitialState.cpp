#include "support/InitialState.h"
#include "MyMath.h"
#include <iostream>
double triangle(double x, int l, double h, double lN1, double lN2);
double AnalyticalStepDown(double lN1, double lN2, double x, int t);

InitialState::InitialState(int iSize, int jSize, int kSize, Conditions * conditions)
	:State(iSize, jSize, kSize, conditions)
{

}

InitialState::InitialState(int iSize, int jSize, int kSize, Conditions * conditions,
	  std::vector <int> timeMomentsForGNUplotMaker, std::string name, double lN1, double lN2,
	  std::function <double(double, int, double, double, double)>
						   initialStateMaker)
	:InitialState(iSize, jSize, kSize, conditions)
{
	m_timeMomentsForGNUplotMaker = timeMomentsForGNUplotMaker;
	m_name = name;
	for (int i = 0; i < this->iSize(); i++) {
			  for (int j = 0; j < this->jSize(); j++) {
					  for (int k = 0; k < this->kSize(); k++) {
						  //double x, int l, double h, double lN1, double lN2
						  static double x;
						  x = i * this->getConditions()->getSpatialStep();
						  static int l;
						  l = k;
						  static double h;
						  h = this->getConditions()->getSpatialStep();

						  this->operator ()(i, j, k) =
						  initialStateMaker(x, l, h, lN1, lN2);
					  }
			  }
	}
}


std::string InitialState::getName() const
{
	return m_name;
}
const std::vector <int> &InitialState::getTimeMoments() const
{
	return m_timeMomentsForGNUplotMaker;
}

State InitialState::getState() const
{
	State temp(this->iSize(), this->jSize(), this->kSize(),
			   this->getConditions());

	for (int i = 0; i < this->iSize(); i++) {
			  for (int j = 0; j < this->jSize(); j++) {
					  for (int k = 0; k < this->kSize(); k++) {
							 temp(i, j, k) = this->operator ()(i, j, k);
					  }
			  }
	}
	return temp;
}

double triangle(double x, int l, double h, double lN1, double lN2)
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

	if (x == 0)
	{

	}
	else
	{
		assert(!std::isnan   (x));
		assert(!std::isinf   (x));
		assert( std::isfinite(x));
	}


	if (l == 0)
	{

	}
	else
	{
		assert(!std::isnan   (l));
		assert(!std::isinf   (l));
		assert( std::isfinite(l));
		assert((0 <= l) && (l <= 20));
	}

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

		xPrev = x - h * 0.5;
		xNext = x + h * 0.5;
		assert((l == 0) || (l == 1));
		switch (l)
		{
		case 0:

				if ((lN1 <= xPrev) && (xNext <= middle))
				{
//						intervalN1 = ((2.0) / (h * (lN2 - lN1))) *
//												 (
//												 xNext * (xNext / 2.0 - lN1) -
//												 xPrev * (xPrev / 2.0 - lN1)
//												 );

						intervalN1 =			 (
												 xNext * (xNext - 2.0 * lN1) -
												 xPrev * (xPrev - 2.0 *  lN1)
												 ) / (h * (lN2 - lN1));
						intervalN2 = 0.0;
				return intervalN1;
				break;
				}


				if ((xPrev <= middle ) && (middle < xNext))
				{
						intervalN1 =			 (
												 middle * (middle - 2.0 * lN1) -
												 xPrev * (xPrev - 2.0 *  lN1)
												 ) / (h * (lN2 - lN1));

						intervalN2 = 			 (
												 xNext * (2.0 * lN2 - xNext) -
												 middle * (2.0 * lN2 - middle)
												 )  / (h * (lN2 - lN1));
						return intervalN1 + intervalN2;
						break;
				}

				if ((middle < xPrev) && (xNext <= lN2))
				{
						intervalN1 = 0.0;

						intervalN2 = 			 (
												 xNext * (2.0 * lN2 - xNext) -
												 xPrev * (2.0 * lN2 - xPrev)
												 )  / (h * (lN2 - lN1));
						return intervalN2;

						break;
				}

				if ((xPrev <= lN2) && (lN2 < xNext))
				{
						intervalN1 = 0.0;
						intervalN2 = 			 (
												 lN2 * (2.0 * lN2 - lN2) -
												 xPrev * (2.0 * lN2 - xPrev)
												 )  / (h * (lN2 - lN1));
						return intervalN2;

						break;
				}

				if (lN2 < xPrev)
				{
						intervalN1 = 0.0;
						intervalN2 = 0.0;
						return 0.0;
						break;
				}

		case 1:
				if ((lN1 <= xPrev) && (xNext <= middle))
				{
						intervalN1 = (
						4.0 * (xNext * xNext * xNext - xPrev * xPrev * xPrev) -
						6.0 * x * (xNext * xNext - xPrev * xPrev) -
						6.0 * lN1 * (xNext * xNext - xPrev * xPrev) +
						12.0 * x * lN1 * (xNext - xPrev)
									 ) / (h * h * (lN2 - lN1));
						intervalN2 = 0.0;
						return intervalN1;
				break;
				}

				if ((xPrev <= middle) && (middle < xNext))
				{
					intervalN1 = (
					4.0 * (middle * middle * middle - xPrev * xPrev * xPrev) -
					6.0 * x * (middle * middle - xPrev * xPrev) -
					6.0 * lN1 * (middle * middle - xPrev * xPrev) +
					12.0 * x * lN1 * (middle - xPrev)
								 ) / (h * h * (lN2 - lN1));

					intervalN2 = (
					 -4.0 * (xNext * xNext * xNext - middle * middle * middle) +
					 6.0 * x * (xNext * xNext - middle * middle) +
					 6.0 * lN2 * (xNext * xNext - middle * middle) -
					 12.0 * x * lN2 * (xNext - middle)
								  ) / (h * h * (lN2 - lN1));

					return intervalN1 + intervalN2;
						break;
				}

				if ((middle <= xPrev) && (xNext <= lN2))
				{
						intervalN1 = 0.0;
						intervalN2 = (
						 -4.0 * (xNext * xNext * xNext - xPrev * xPrev * xPrev) +
						 6.0 * x * (xNext * xNext - xPrev * xPrev) +
						 6.0 * lN2 * (xNext * xNext - xPrev * xPrev) -
						 12.0 * x * lN2 * (xNext - xPrev)
									  ) / (h * h * (lN2 - lN1));
						return intervalN2;
						break;
				}

				if ((xPrev <= lN2) && (lN2 < xNext))
				{
						intervalN1 = 0.0;
						intervalN2 = (
						 -4.0 * (lN2 * lN2 * lN2 - xPrev * xPrev * xPrev) +
						 6.0 * x * (lN2 * lN2 - xPrev * xPrev) +
						 6.0 * lN2 * (lN2 * lN2 - xPrev * xPrev) -
						 12.0 * x * lN2 * (lN2 - xPrev)
									  ) / (h * h * (lN2 - lN1));
						return intervalN2;
						break;
				}

				if (lN2 < xPrev)
				{
						intervalN1 = 0.0;
						intervalN2 = 0.0;
						return 0.0;
						break;
				}
		}

		if (intervalN1 != 0)
		{
			assert(!std::isnan   (intervalN1));
			assert(!std::isinf   (intervalN1));
			assert( std::isfinite(intervalN1));
		}

		if (intervalN2 != 0)
		{
			assert(!std::isnan   (intervalN2));
			assert(!std::isinf   (intervalN2));
			assert( std::isfinite(intervalN2));
		}
		if (intervalN2 == 0)
				return intervalN1;
		if (intervalN1 == 0)
				return intervalN2;
		else
			return intervalN1 + intervalN2;
}

std::vector <double> InitialState::makeAnalyticalValueVector(int t) const
{
	assert((this->kSize() == 1) || (this->kSize() == 2));

	static int valueGridSize = this->iSize() * this->kSize();
	static std::vector <double> value(valueGridSize);

		static double x;
		static double newH;
		newH =  this->getConditions()->getSpatialStep() / this->kSize();
		for (int i = 0; i < valueGridSize; i++)
		{
			x =  i * newH;
			value[i] = AnalyticalTriangle (0.0, 20.0, x, t);
//			value[i] = AnalyticalStepDown (0.0, 20.0, x, t);

//			value[i] = AnalyticalSolution (0.0, 20.0, x, t);
		}

	return value;
	std::range_error("reached end of makeValue function and didn't calculated anything");
	std::vector <double> error = {1.0};
	return error;
}

double AnalyticalStepDown(double lN1, double lN2, double x, int t)
{
	if ((lN1 <= x) && (x <= (lN1 + 0.5 * t)))
	{
		return 1.0;
	}
	else
	{
		return 0.0;
	}
}


