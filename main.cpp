#include <iostream>
#include <cmath>

#include "support/Conditions.h"
#include "support/State.h"
#include "support/Problem.h"

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

#include "systemSolvers/SystemSolver.h"
#include "systemSolvers/RungeKuttaSystemSolver.h"
#include "systemSolvers/EulerSystemSolver.h"

#include "support/MyMath.h"

int main ()
{

	// прикрутить человеческие начальные условия
	// затычки заменить на расчёты нормальные
	// мэйн подправить
	// довести до кипения
	// добавить гну плот
	// докрутить хуюльки

	const double a = 0.0;
	const double b = 520.0;
	const double spatialStep = 1;
	const int spatialSteps = static_cast <int>(std::floor((b - a) / spatialStep));

	const double T = 100.0;
	const double courantNumber = 0.1;
	//?
	const double velocityMagnitude = 1.0;
	const double timeStep  = (courantNumber * spatialStep) / velocityMagnitude;
	const int timeSteps = static_cast <int>(T / timeStep);

	Conditions conditions(spatialStep, timeStep, spatialSteps, timeSteps, a, b, T);
	Problem problem;

	const int k = 1;

	//Streams
//	GodunovStream godunovStream(& problem);
////	EOStream EOstream(& problem);
////	LFStream LFstream(& problem);
////	LLFstream LLFstream (&problem);
////	RStream Rstream (& problem);

//	GalerkinSystemMaker galerkinSystemMaker(&problem, &conditions,
//											&godunovStream, k);

//	//TVDM limiters
////	MUSCLLimiter MUSCLLimiter(&conditions);
////	LimiterN2 limiterN2 (& conditions);
////	LimiterN3 limiterN3 (& conditions);

////	//TVBM limiters

////	MUSCLLimiterBM MUSCLlimiterBM(& conditions);
////	LimiterN2BM limitrN2BM  (&conditions);
////	LimiterN3BM limiterN3BM (&conditions);

//	RungeKuttaSystemSolver rungeKuttaSystemSolver(&MUSCLLimiter, &conditions,
//												  &galerkinSystemMaker);
	//Initial States
	//Cheeke
	//Breeke

//	Solver solver (&rungeKuttaSystemSolver, &conditions, a, b, T);

//	///inside the solver:
//	/// writer.setNumericalSolutionSource(...);
//	/// etc for error and analytical
//	///

//	/*
//	 * Solver solver(& galerkinSystemMaker, & eulerSystemMaker, & conditions);
//	 * solver.solveAll(limiters, streams, initialStates);
//	 * return 0;

//	for (int t = 0; t < timeSteps; t++)
//	{
//		solver.makeGNUplots;
//		solver.write();
//		// writes numerical solution, analytic solution and error
//		solver.solve();
//	}
	// вектор указателей на лимитеры-хуитеры, стримы-хуимы, туда сюда толкаешь
	// как насвай по дёснам

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

	return 0;
}
