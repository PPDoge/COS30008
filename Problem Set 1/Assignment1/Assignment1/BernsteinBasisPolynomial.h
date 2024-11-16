#pragma once
#include "Combination.h"
// https://en.wikipedia.org/wiki/Bernstein_polynomial
class BernsteinBasisPolynomial
{
private:
	Combination fFactor;

public:

	BernsteinBasisPolynomial(unsigned int aV = 0, unsigned int aN = 0);

	double operator()(double aX) const;
};