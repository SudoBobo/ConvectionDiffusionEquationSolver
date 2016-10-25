#include "support/State.h"

#include <exception>
#include <stdexcept>
#include <assert.h>

#include "support/MyMath.h"

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

State::State()
{
	m_state = nullptr;
	m_conditions = nullptr;
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
		if((i > m_iSize) || (j > m_jSize) || (k > m_kSize) ||(i < 0)||(j<0)||(k <0))
				throw std::range_error("Try to get an access to point that doesn't exist");

		return m_state[i][j][k];
}

Polynomial State::operator()(int i, int j) const
{
		if((i > m_iSize) || (j > m_jSize) ||(i < 0)||(j<0))
				throw std::range_error("Try to get an access to point that doesn't exist");

		// ещё проблема с размерами сетки

		//!!! так было раньше
		int polynomialOrder = m_kSize - 1;
		Polynomial temp(m_state[i][j], i, polynomialOrder);

		// кажется, правильный вариант
		// нет, неправильный m_kSize = 1 для полинома порядка
//		Polynomial temp(m_state[i][j], i, m_kSize);

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
		if((i > m_iSize) || (j > m_jSize) || (k > m_kSize) || (i <0)||(j <0) || (k<0))
				throw std::range_error("Try to get an access to point that doesn't exist");

		return m_state[i][j][k];
}

State & State:: operator =(const State & anotherState)
{
		if (this == &anotherState)
		{
			return *this;
		}
		if (m_state != nullptr)
		{
			for (int i = 0; i < m_iSize; i++){
					for (int j = 0; j < m_jSize; j++){
							delete [] m_state[i][j];
					}
					delete [] m_state[i];
			}
			delete [] m_state;
		}

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

//State & State::operator = (const InitialState & anotherState)
//{
//	for (int i = 0; i < m_iSize; i++){
//			for (int j = 0; j < m_jSize; j++){
//					delete [] m_state[i][j];
//			}
//			delete [] m_state[i];
//	}
//	delete [] m_state;

//	this->m_iSize = anotherState.iSize();
//	this->m_jSize = anotherState.jSize();
//	this->m_kSize = anotherState.kSize();
//	this->m_conditions = anotherState.getConditions();




//	m_state = new double** [m_iSize];
//	for (int i = 0; i < m_iSize; i++) {
//			  m_state[i] = new double* [m_jSize];
//			  for (int j = 0; j < m_jSize; j++) {
//					  m_state[i][j] = new double[m_kSize];
//					  for (int k = 0; k < m_kSize; k++) {
//							  m_state[i][j][k] = anotherState(i, j, k);
//					  }
//			  }
//	}
//	return *this;
//}

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

	assert(!std::isnan   (coefficient));
	assert(!std::isinf   (coefficient));
	assert( std::isfinite(coefficient));

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

std::vector <double> State::makeValueVector() const
{
	assert((this->kSize() == 1) || (this->kSize() == 2));

	static int valueGridSize = m_iSize * m_kSize;
	static std::vector <double> value(valueGridSize);

	if (this->kSize() == 1)
	{
		for (int i = 0; i < value.size(); i++)
		{
			value[i] = m_state[i][0][0]; /*calcAvgValue(1, j, m_conditions->getSpatialStep(),
									this->operator ()(i, j));*/
		}
		return value;
	}

	if (this->kSize() == 2)
	{
		static double x;

		for (int i = 0; i < m_iSize; i++)
		{
			static double h;
			h = m_conditions->getSpatialStep();
			// with another division the calculations may be more accurate

			// OH MY
			// x = i * h;
			x = i * h + h * 0.5;
//			value[2 * i]     = m_state[i][0][0];
//			value[2 * i + 1] = m_state[i][0][0];

			assert(!std::isnan   (x));
			assert(!std::isinf   (x));
			assert( std::isfinite(x));
// Lol wut?
			value[i * 2] = m_state[i][0][0] + m_state[i][0][1] *
						   (((x + h * 0.25) - (x + h * 0.5)) / h);

			assert(!std::isnan   (value[i * 2]));
			assert(!std::isinf   (value[i * 2]));
			assert( std::isfinite(value[i * 2]));

			x += m_conditions->getSpatialStep() / 2.0;

			assert(!std::isnan   (x));
			assert(!std::isinf   (x));
			assert( std::isfinite(x));

			value[i * 2 + 1] = m_state[i][0][0] + m_state[i][0][1] *
						   (((x + h * 0.75) - (x + h * 0.5)) / h);

			assert(!std::isnan   (value[i * 2 + 1]));
			assert(!std::isinf   (value[i * 2 + 1]));
			assert( std::isfinite(value[i * 2 + 1]));

		}
		return value;
	}
	std::range_error("reached end of makeValue function and didn't calculated anything");
	std::vector <double> error = {1.0};
	return error;
}

Conditions * State::getConditions() const
{
	return m_conditions;
}

int State::valueVectorSize() const
{
	return m_iSize * m_kSize;
}

bool State::operator ==(const State & anotherState)
{
	return (((m_iSize == anotherState.iSize()) && (m_jSize == anotherState.jSize())
			&& (m_kSize == anotherState.kSize())) &&
			(m_conditions == anotherState.getConditions()));
}

double State::sum() const
{
	assert(m_jSize == 1);

	static double sum;
	sum = 0.0;

	if (m_kSize == 1)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			sum += m_state[i][0][0];
		}
	return sum;
	}

	static double xJ;
	static double xJprev;
	static double xJnext;
	static double h = m_conditions->getSpatialStep();

	if (m_kSize == 2)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			xJ = i * h + h * 0.5;
			xJnext = i * h + h;
			xJprev = i * h;

			sum +=  m_state[i][0][0] +
			((2.0 * m_state[i][0][1] / h) *
			((xJnext*xJnext - xJprev*xJprev)/2.0 - xJ *(xJnext - xJprev))) / h;
		}
	return sum;
	}

	if (2 < m_kSize)
	{
		throw std::range_error("No sum function for k > 2");
	}
}

double State::UMax() const
{
	static double UMax;
	UMax = 0.0;

	if (m_kSize == 1)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			if (UMax < m_state[i][0][0])
			{
				UMax = m_state[i][0][0];
			}
		}
	return UMax;
	}

	static double xJ;
	static double xJprev;
	static double xJnext;
	static double uValue;
	uValue = 0.0;
	static double h = m_conditions->getSpatialStep();

	if (m_kSize == 2)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			xJ = i * h + h * 0.5;
			xJnext = i * h + h;
			xJprev = i * h;

			uValue =  m_state[i][0][0] +
			((2.0 * m_state[i][0][1] / h) *
			((xJnext*xJnext - xJprev*xJprev)/2.0 - xJ *(xJnext - xJprev))) / h;

			if(UMax < uValue)
			{
				UMax = uValue;
			}
		}
	return UMax;
	}

	if (2 < m_kSize)
	{
		throw std::range_error("No UMax function for k > 2");
	}
}
