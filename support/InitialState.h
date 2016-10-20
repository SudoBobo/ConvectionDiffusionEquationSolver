#ifndef INITIALSTATE_H
#define INITIALSTATE_H

#include "support/State.h"
#include <functional>

#include <string>

class InitialState : public State
{
public:
	InitialState(int iSize, int jSize, int kSize, Conditions * conditions);
	// помимо initialStateMaker'a стоит ещё передавать analyticalSolver
	InitialState(int iSize, int jSize, int kSize, Conditions * conditions,
		  std::vector <int> timeMomentsForGNUplotMaker, std::__cxx11::string name, double lN1, double lN2,
		  std::function <double(double, int, double, double, double)>
				 initialStateMaker);

	std::string getName() const;
	const std::vector <int> & getTimeMoments() const;
	State getState() const;

	std::vector <double> makeAnalyticalValueVector(int t) const;


private:
	std::vector <int> m_timeMomentsForGNUplotMaker;
	std::function <double(double, int, double, double, double)>
		   m_analyticalStateMaker;
	std::string m_name;
};

#endif // INITIALSTATE_H
