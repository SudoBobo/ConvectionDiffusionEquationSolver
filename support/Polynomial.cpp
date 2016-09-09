#include "support/Polynomial.h"

#include <exception>
#include <stdexcept>

Polynomial::Polynomial(const double * coefficients, const int j, const int k)
	:m_coefficients(k+1)
{
	for (int l = 0; l <= k; l++)
	{
		m_coefficients[l] = coefficients[l];
	}
	m_j = j;
	m_k = k;
}

Polynomial::Polynomial()
{

}

Polynomial::Polynomial(const int j, const int k)
	:m_coefficients(k+1), m_j(j), m_k(k)
{

}

Polynomial::Polynomial(const Polynomial & anotherPolynomial)
	:m_coefficients(anotherPolynomial.getCoefficients()),
	 m_j(anotherPolynomial.getJ()), m_k(anotherPolynomial.getOrder())
{

}

Polynomial & Polynomial::operator = (const Polynomial & anotherPolynomial)
{
	m_coefficients = anotherPolynomial.getCoefficients();
	m_j = anotherPolynomial.getJ();
	m_k = anotherPolynomial.getOrder();
}

double Polynomial::operator  () (int l) const
{
	if (m_k < l)
		throw std::range_error("try to get a coefficient of l > k");

	return m_coefficients[l];
}

double & Polynomial::operator() (int l)
{
	if (m_k < l)
		throw std::range_error("try to get a coefficient of l > k");

	return m_coefficients[l];
}

int Polynomial::getOrder () const
{
	return m_k;
}

int Polynomial::getJ () const
{
	return m_j;
}

void Polynomial::setJ(const int newJ)
{
	m_j = newJ;
}

std::vector <double> Polynomial::getCoefficients() const
{
	return m_coefficients;
}
