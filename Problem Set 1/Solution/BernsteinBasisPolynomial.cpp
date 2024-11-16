#include "BernsteinBasisPolynomial.h"

#include <cmath>

using namespace std;

BernsteinBasisPolynomial::BernsteinBasisPolynomial( unsigned int aV, unsigned int aN ) :
    fFactor(aN, aV)                                                     
{}

double BernsteinBasisPolynomial::operator()( double aX ) const
{
    double Result = fFactor() * pow( aX, fFactor.getK() );             
    
    return Result * pow( 1 - aX, fFactor.getN() - fFactor.getK() );     
}                                                                       
