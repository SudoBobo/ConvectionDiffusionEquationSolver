#ifndef MYMATH_H
#define MYMATH_H

#include "support/Polynomial.h"
#include <functional>
using namespace std;
//вычисляет среднее значение величины u по промежутку j
//это значение также используется как численное значение u в точке x(j)
double calcAvgValue(const double spatialStep,
				 const Polynomial & u);
double integral23(const int l, const double spatialStep,
				  const Polynomial &u);
//double u0Triangle(double x, int l, double h, double lN1, double lN2);
// time = t * tau
//double AnalyticalTriangle (double lN1, double lN2, double x, double time);

double twoDimIntegralForNorm
(double(* u) (double *, size_t, void *),
 double lN1, double lN2, double x0, double xMax,
 double time0, double timeMax);


// m - function from limiter definition from article
//http://keldysh.ru/papers/2005/prep105/prep2005_105.html
double m(double a, double b);
double m (double a, double b, double c);
double m(double a, double b, double c, double d);
double mForBMLimiters (double a, double b, double c);
int sgn (double val);
#endif // MYMATH_H
