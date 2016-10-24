#ifndef STATE_H
#define STATE_H

#include "support/Conditions.h"
#include "support/Polynomial.h"
#include "support/State.h"

#include <vector>
#include <assert.h>
#include <cmath>

//checked
class State
{
public:
	// i == pointN, j == valueN, k == basisFunctionN
	State(int iSize, int jSize, int kSize, Conditions * conditions);
	State();
	~State();
	State(const State & anotherState);

	State operator +(const State & anotherState) const;
	State operator *(double coefficient) const;
	State & operator = (const State & anotherState);
//	State & operator = (const InitialState & initialState);
	bool operator == (const State & anotherState);

	double     operator ()  (int i, int j, int k) const;
	Polynomial  operator ()  (int i, int j) const;
	double & operator()  (int i, int j, int k);
	void operator ()(int i, int j, Polynomial &newPolynomial);

	std::vector <double> makeValueVector() const;
	int valueVectorSize() const;

	int iSize() const;
	int jSize() const;
	int kSize() const;

	int spatialOrder() const;
	Conditions * getConditions() const;
	double UMax() const;
	double sum() const;

private:
	int        m_iSize, m_jSize, m_kSize;
	double *** m_state;
	Conditions * m_conditions;
};

#endif // STATE_H
