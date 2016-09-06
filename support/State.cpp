#include "State.h"

#include <exception>
#include <stdexcept>
#include <assert.h>

#include "MyMath.h"

State::State(int iSize, int jSize, int kSize, Conditions * conditions)

{
		this->m_iSize = iSize;
		this->m_jSize = jSize;
		this->m_kSize = kSize;
		this->m_conditions = conditions;

		m_state = new double** [m_iSize];
		for (int i = 0; i < m_iSize; i++)
		{
				  m_state[i] = new double* [m_jSize];
				  for (int j = 0; j < m_jSize; j++)
				  {
						  m_state[i][j] = new double[m_kSize];
				  }
		}
}

State::State(const State & anotherState)
{
		this->m_iSize = anotherState.iSize();
		this->m_jSize = anotherState.jSize();
		this->m_kSize = anotherState.kSize();
		this->m_conditions = anotherState.getConditions();

		m_state = new double** [m_iSize];
		for (int i = 0; i < m_iSize; i++)
		{
				  m_state[i] = new double* [m_jSize];
				  for (int j = 0; j < m_jSize; j++)
				  {
						  m_state[i][j] = new double[m_kSize];
						  for (int k = 0; k < m_kSize; k++)
						  {
								  m_state[i][j][k] = anotherState(i, j, k);
						  }
				  }
		}
}

State::~State()
{
	for (int i = 0; i < m_iSize; i++)
	{
			  for (int j = 0; j < m_jSize; j++)
			  {
					  delete [] m_state[i][j];
			  }
			  delete [] m_state[i];
	}
	delete [] m_state;
}

double State::operator()(int i, int j, int k) const
{
		if((i > m_iSize) || (j > m_jSize) || (k > m_kSize) ||(i < 0)||(j<0)
																																		||(k <0))
				throw std::range_error("Try to get an access to point that doesn't exist");

		return m_state[i][j][k];
}

Polynomial State::operator()(int i, int j) const
{
		if((i > m_iSize) || (j > m_jSize) ||(i < 0)||(j<0))
				throw std::range_error("Try to get an access to point that doesn't exist");

		Polynomial temp(m_state[i][j], i, m_kSize - 1);
		return temp;
}

void State::operator ()(int i, int j, Polynomial & newPolynomial)
{
	if((i > m_iSize) || (j > m_jSize) ||(i < 0)||(j<0))
			throw std::range_error("Try to get an access to point that doesn't exist");

	static int polynomialSize;
	polynomialSize = newPolynomial.getOrder() + 1;

	if (polynomialSize != m_kSize)
		throw std::range_error("Try to assign polynomial of a wrong size");

	for (int l = 0; l < m_kSize; l++)
	{
		m_state[i][j][l] = newPolynomial(l);
	}
}

double & State::operator()(int i, int j, int k)
{
		if((i > m_iSize) || (j > m_jSize) || (k > m_kSize) || (i <0)||(j <0)
																																		 || (k<0))
				throw std::range_error("Try to get an access to point that doesn't exist");

		return m_state[i][j][k];
}

State & State:: operator =(const State & anotherState)
{
		if (this == &anotherState)
		{
			return *this;
		}

		for (int i = 0; i < m_iSize; i++){
				for (int j = 0; j < m_jSize; j++){
						delete [] m_state[i][j];
				}
				delete [] m_state[i];
		}
		delete [] m_state;

		this->m_iSize = anotherState.iSize();
		this->m_jSize = anotherState.jSize();
		this->m_kSize = anotherState.kSize();
		this->m_conditions = anotherState.getConditions();




		m_state = new double** [m_iSize];
		for (int i = 0; i < m_iSize; i++) {
				  m_state[i] = new double* [m_jSize];
				  for (int j = 0; j < m_jSize; j++) {
						  m_state[i][j] = new double[m_kSize];
						  for (int k = 0; k < m_kSize; k++) {
								  m_state[i][j][k] = anotherState(i, j, k);
						  }
				  }
		}
		return *this;
}

int State::iSize() const
{
		return m_iSize;
}

int State::jSize() const
{
		return m_jSize;
}

int State::kSize() const
{
		return m_kSize;
}

int State::spatialOrder() const
{
		return m_kSize - 1;
}

State State::operator +(const State & anotherState) const
{
		State temp(m_iSize, m_jSize, m_kSize, m_conditions);
		for (int i = 0; i < m_iSize; i++)
		{
				  for (int j = 0; j < m_jSize; j++)
				  {
						  for (int k = 0; k < m_kSize; k++)
						  {
								  temp(i, j, k) = m_state[i][j][k] + anotherState(i, j, k);
						  }
				  }
		}
		return temp;
}

State State::operator *(double coefficient) const
{
		State temp(m_iSize, m_jSize, m_kSize, m_conditions);
		for (int i = 0; i < m_iSize; i++)
		{
				  for (int j = 0; j < m_jSize; j++)
				  {
						  for (int k = 0; k < m_kSize; k++)
						  {
								  temp(i, j, k) = m_state[i][j][k] * coefficient;
						  }
				  }
		}
		return temp;
}

std::vector <double> State::makeValueVector(const int j) const
{
	assert((this->kSize() == 1) || (this->kSize() == 2));

	static int valueGridSize = m_iSize * m_kSize;
	static std::vector <double> value(valueGridSize);

	if (this->kSize() == 1)
	{
		for (int i = 0; i < value.size(); i++)
		{
			value[i] = 42; /*calcAvgValue(1, j, m_conditions->getSpatialStep(),
									this->operator ()(i, j));*/
		}
		return value;
	}

	if (this->kSize() == 2)
	{
		for (int i = 0; i < value.size(); i++)
		{	// x(j-1/2)
			if ((i % 2) == 0)
			{
				value[i] = 42;
			}
			// x(j+1/2)
			else
			{
				value [i] = 42;
			}
		}
		return value;
	}
}
Conditions * State::getConditions() const
{
	return m_conditions;
}

int State::valueVectorSize() const
{
	return m_iSize * m_kSize;
}
