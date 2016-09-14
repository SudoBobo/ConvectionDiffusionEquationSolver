#include "support/InitialState.h"

InitialState::InitialState(int iSize, int jSize, int kSize, Conditions * conditions)
	:State(iSize, jSize, kSize, conditions)
{

}

InitialState::InitialState(int iSize, int jSize, int kSize, Conditions * conditions,
	  std::vector <int> time, std::string name)
	:InitialState(iSize, jSize, kSize, conditions)
{
	m_timeMomentsForGNUplotMaker = time;
	m_name = name;
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
