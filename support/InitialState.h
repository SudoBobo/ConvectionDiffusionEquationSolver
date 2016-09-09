#ifndef INITIALSTATE_H
#define INITIALSTATE_H

#include "support/State.h"
#include <string>

class InitialState : public State
{
public:
	InitialState(int iSize, int jSize, int kSize, Conditions * conditions);
	InitialState(int iSize, int jSize, int kSize, Conditions * conditions,
		  std::vector <int> time);
	std::string m_name() const;

private:
	std::vector <int> m_timeMomentsForGNUplotMaker;
};

#endif // INITIALSTATE_H
