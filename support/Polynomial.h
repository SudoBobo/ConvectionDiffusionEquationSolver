#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>

class Polynomial
{
public:
	Polynomial(const double * coefficients, const int j, const int k);
	Polynomial(const int j, const int k);
	Polynomial(const Polynomial & anotherPolynomial);
	Polynomial();
	Polynomial & operator = (const Polynomial & anotherPolynomial);
	double operator  () (int l) const;
		  double & operator() (int l);
	std::vector <double> getCoefficients() const;
	int getOrder () const;
	// номер точки на координатной оси
	int getJ () const;
	void setJ(const int newJ);
private:
	std::vector <double> m_coefficients;
	int m_j;
	int m_k;
};

#endif // POLYNOMIAL_H
