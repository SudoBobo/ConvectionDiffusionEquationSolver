#ifndef STATE_H
#define STATE_H

#include "support/Conditions.h"
#include <vector>

//checked
class State
{
public:
	// i == pointN, j == valueN, k == basisFunctionN
	State(int iSize, int jSize, int kSize, Conditions * conditions);
	~State();
	State(const State & anotherState);

	State operator +(const State & anotherState) const;
	State operator *(double coefficient) const;
	State & operator = (const State & anotherState);

	double     operator ()  (int i, int j, int k) const;
	const double *   operator ()  (int i, int j) const;
	double & operator()  (int i, int j, int k);
	double * operator () (int i, int j);

	std::vector <double> makeValueVector(const int j) const;
	int valueVectorSize() const;

	int iSize() const;
	int jSize() const;
	int kSize() const;

	int spatialOrder() const;
	Conditions * getConditions() const;

private:
	int        m_iSize, m_jSize, m_kSize;
	double *** m_state;
	Conditions * m_conditions;
};

#endif // STATE_H
