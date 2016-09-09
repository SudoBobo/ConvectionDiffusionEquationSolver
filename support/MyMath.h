#ifndef MYMATH_H
#define MYMATH_H

#include "support/Polynomial.h"

//вычисляет среднее значение величины u по промежутку j
//это значение также используется как численное значение u в точке x(j)
double calcAvgValue(const double spatialStep,
				 const Polynomial & u);
double integral23(const int l, const double spatialStep,
				  const Polynomial &u);

// m - function from limiter definition from article
//http://keldysh.ru/papers/2005/prep105/prep2005_105.html
double m(double a, double b);
double m (double a, double b, double c);
double m(double a, double b, double c, double d);
double mForBMLimiters (double a, double b, double c);
int sgn (double val);

#endif // MYMATH_H
