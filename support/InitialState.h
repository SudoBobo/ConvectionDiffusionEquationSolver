#ifndef INITIALSTATE_H
#define INITIALSTATE_H

#include "support/State.h"

#include <string>

class InitialState : public State
{
public:
	InitialState(int iSize, int jSize, int kSize, Conditions * conditions);
	InitialState(int iSize, int jSize, int kSize, Conditions * conditions,
		  std::vector <int> time, std::__cxx11::string name);
	std::string getName() const;
	const std::vector <int> & getTimeMoments() const;
	State getState() const;

private:
	std::vector <int> m_timeMomentsForGNUplotMaker;
	std::string m_name;
};

#endif // INITIALSTATE_H
