#include "support/InitialState.h"

InitialState::InitialState(int iSize, int jSize, int kSize, Conditions * conditions)
	:State(iSize, jSize, kSize, conditions)
{

}

InitialState::InitialState(int iSize, int jSize, int kSize, Conditions * conditions,
	  std::vector <int> time, std::string name, double lN1, double lN2,
	  std::function <double(double, int, double, double, double)>
						   initialStateMaker)
	:InitialState(iSize, jSize, kSize, conditions)
{
	m_timeMomentsForGNUplotMaker = time;
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
