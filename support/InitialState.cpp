#include "InitialState.h"

InitialState::InitialState(int iSize, int jSize, int kSize, Conditions * conditions)
	:State(iSize, jSize, kSize, conditions)
{

}

InitialState::InitialState(int iSize, int jSize, int kSize, Conditions * conditions,
	  std::vector <int> time)
	:InitialState(iSize, jSize, kSize, conditions)
{
	m_timeMomentsForGNUplotMaker = time;
}
