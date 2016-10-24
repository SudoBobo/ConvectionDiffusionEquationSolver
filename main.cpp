#include <iostream>
#include <cmath>

#include "support/Conditions.h"
#include "support/State.h"
#include "support/InitialState.h"
#include "support/Problem.h"
#include "support/Solver.h"
#include "systemMakers/SystemMaker.h"
#include "systemMakers/GalerkinSystemMaker.h"



#include "limiters/Limiter.h"
#include "limiters/MUSCLLimiter.h"
//#include "limiters/LimiterN2.h"
//#include "limiters/LimiterN3.h"
//#include "limiters/MUSCLLimiterBM.h"
//#include "limiters/LimiterN2BM.h"
//#include "limiters/LimiterN3BM.h"


#include "streams/Stream.h"
#include "streams/GodunovStream.h"
#include "streams/EOStream.h"
#include "streams/LFStream.h"

#include "systemSolvers/SystemSolver.h"
#include "systemSolvers/RungeKuttaSystemSolver.h"
#include "systemSolvers/EulerSystemSolver.h"

#include "support/MyMath.h"
double u0StepDown (double x, double l, double h, double lN1, double lN2);
double AnalyticalStepDown(double lN1, double lN2, double x, double time);
double u0Triangle(double x, int l, double h, double lN1, double lN2);
double AnalyticalTriangle (double lN1, double lN2, double x, double time);

int main ()
{
	// аналитическое решение генрирует
	// добавить гну плот

	const double a = 0.0;
	const double b = 520.0;
	const double spatialStep = 0.5;
	const int spatialSteps = static_cast <int>(std::floor((b - a) / spatialStep));

	const double T = 100;
	const double courantNumber = 0.5;
	//?
	const double velocityMagnitude = 1.0;
	const double timeStep  = (courantNumber * spatialStep) / velocityMagnitude;
	const int timeSteps = static_cast <int>(T / timeStep);
	std::cout << "Full time = " << T << "seconds" << std::endl;
	std::cout << "TimeStep = " << timeStep << std::endl;
//fine
	const int k = 1;

	Conditions conditions(spatialStep, timeStep, spatialSteps, timeSteps, a, b,
						  T, k);
	Problem problem;
//fine
	std::vector <int> timeToMakeGNUPlots = {0, 10};
	const int jSize = 1;

	std::string name = "Triangle";
	///!
	//! \brief triangleInitialState
	//!
	std::vector <InitialState*> initialStates;

	InitialState triangleInitialState(spatialSteps, jSize, k+1, &conditions,
							  timeToMakeGNUPlots, name, 0.0, 20.0,
							   u0Triangle, AnalyticalTriangle);
//	initialStates.push_back(&triangleInitialState);


	name = "StepDown";
	InitialState stepDownInitialState(spatialSteps, 1, k+1, &conditions,
							  timeToMakeGNUPlots, name, 0.0, 20.0,
							   u0StepDown, AnalyticalStepDown);
	initialStates.push_back(&stepDownInitialState);

	//Streams
	GodunovStream godunovStream(& problem);
//	std::vector <Stream*> streams;

//	EOStream EOstream (& problem);
//	LFStream LFstream (& problem);

	std::vector <Stream*> streams;
//	streams.push_back(&EOstream);
//	streams.push_back(&LFstream);
	streams.push_back(&godunovStream);


////	EOStream EOstream(& problem);
////	LFStream LFstream(& problem);
////	LLFstream LLFstream (&problem);
////	RStream Rstream (& problem);

GalerkinSystemMaker galerkinSystemMaker(&problem, &conditions, k);

//	//TVDM limiters
	MUSCLLimiter MUSCLlimiter(&conditions, k);
	std::vector <Limiter*> limiters;
	limiters.push_back(&MUSCLlimiter);

////	LimiterN2 limiterN2 (& conditions);
////	LimiterN3 limiterN3 (& conditions);

////	//TVBM limiters

////	MUSCLLimiterBM MUSCLlimiterBM(& conditions);
////	LimiterN2BM limitrN2BM  (&conditions);
////	LimiterN3BM limiterN3BM (&conditions);

//	RungeKuttaSystemSolver rungeKuttaSystemSolver(&MUSCLlimiter, &conditions,
//												  &galerkinSystemMaker);
	EulerSystemSolver eulerSystemSolver(&conditions);

	///inside the solver:
	/// writer.setNumericalSolutionSource(...);
	/// etc for error and analytical
	///

	 Solver solver(& galerkinSystemMaker, & eulerSystemSolver, & conditions);
	 solver.solveAll(limiters, streams, initialStates);
//	 std::cout << "test" << std::endl;
//	 double boo = godunovStream(10, 10);
//	 double coef [2] = {5.0, 5.0};
//	 Polynomial testP(coef, 1, 1);

//	State test (1,1,3, & conditions);
//	Polynomial pol (coef,5, 5)
	 return 0;
}

	//!! ТЕСТЫ ОСТАВТЬ ОКАЯННЫЙ !!
//	State s(2, 1, 2, &conditions);
//	for (int i = 0; i < s.iSize(); i++)
//	{
//		for (int j = 0; j < s.jSize(); j++ )
//		{
//			for (int k = 0; k < s.kSize(); k++)
//			{
//				s(i, j, k) = 5;
//			}
//		}
//	}
//	State s1 = s;
//	State s2 = s1 + s;

//	for (int i = 0; i < s.iSize(); i++)
//	{
//		for (int j = 0; j < s.jSize(); j++ )
//		{
//			for (int k = 0; k < s.kSize(); k++)
//			{
//				std::cout << "i = " << i << " j = " << j << " k = " << k << " value = " <<s2(i, j, k) << std::endl;
//			}
//		}
//	}
//	Polynomial temp3(0, 1);
//	std::cout << "temp 3 " << temp3.getJ() << " " << temp3.getOrder() << std::endl;
//	Polynomial temp = s2(0, 0);
//	std::cout << "temp  " << temp.getJ() << " " << temp.getOrder() << std::endl;

//	temp(1) = temp(0) + 1;
//	temp(0) = temp(1);

//	Polynomial temp2(temp);

//	std::cout << "temp = " << temp(0) << " " << temp(1) <<  std::endl;
//	std::cout << "temp2 = " << temp2(0) << " " << temp2(1) <<  std::endl;
//	temp2(0) += 100;
//	std::cout << "temp2 = " << temp2(0) << " " << temp2(1) <<  std::endl;
//	temp = temp2;
//	std::cout << "temp = " << temp(0) << " " << temp(1) <<  std::endl;

//	std::cout << "s2OLD = " <<  s2(0, 0, 0) << " " << s2(0, 0, 1) << std::endl;

//	s2(0, 0, temp);
//	std::cout << "s2NEW = " << s2(0, 0, 0) << " " << s2(0, 0, 1) << std::endl;

//	std::cout << m(1, 2, 3, 4) << std::endl;
//	std::cout << m(3, 1, 4, 1) << std::endl;
//	std::cout << m(-1, -2, -3, -4) << std::endl;
//	std::cout << m(2, 2, 3, 4) << std::endl;


//	std::cout << m(3, 2, 3) << std::endl;
//	std::cout << mForBMLimiters(0,  2, 3) << std::endl;
//	double dick [2];
//	dick[0] = 5;
//	dick[1] = 10;
//	Polynomial ass(dick, 20, 1);
//	std::cout << calcAvgValue(1.0, ass) << std::endl;
//	std::cout << 205 << std::endl;

double u0StepDown (double x, double l, double h, double lN1, double lN2)
{
	static double a;
	static double b;
	// note that in other parts there may be mistake
	// with a = x - h, b = x + h
	// while the right variant is
	// a = x - h * 0.5;
	// b = x + h * 0.5;
	a = x - h * 0.5;
	b = x + h * 0.5;
	int k = static_cast <int> (l);
	switch(k)
	{
	// функция возвращает коэфициенты - нет ли тут ошибки с тем, что мы не
	// используем порядок многочлена?
	case 0:
		if ((0 <= x) && (x <= lN1))
		{
			// u = k * 1
			return 1.0;
			// the same, but more presice
//			return (b - a) / h;
		}
		else
		{
			return 0.0;
		}
	case 1:
		if ((0 <= x) && (x <= lN1))
		{
			return 3.0 * ((b * b - a * a) - 6.0 * x * (b - a)) / (h * h);
		}
		else
		{
			return 0.0;
		}

	}
}

double AnalyticalStepDown(double lN1, double lN2, double x, double time)
{
	// существенно, что t (физическое) = t' (точка на временной сетке) * tau
	if ((lN1 <= x) && (x <= (lN1 + 0.5 * time)))
	{
		return 1.0;
	}
	else
	{
		return 0.0;
	}
}

double AnalyticalTriangle (double lN1, double lN2, double x, double time)
{

	static double t;
	t = time;

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
