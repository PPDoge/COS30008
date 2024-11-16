#include "Polynomial.h"

#include <cmath>

using namespace std;

double Polynomial::operator()( double aX ) const
{
    double Result = 0.0;                                                    
    
    for ( size_t i = 0; i <= fDegree; i++ )                                 
   
        Result += fCoeffs[i] * pow( aX, i );                                
    }
   
    return Result;                                                          
}

Polynomial Polynomial::getDerivative() const
{
    Polynomial Result;                                                      
    
    if ( fDegree )                                                          
    {
        Result.fDegree = fDegree - 1;                                       
        
        for ( size_t i = 0; i < fDegree; i++ )                              
        {
            Result.fCoeffs[i] = (i + 1) * fCoeffs[i + 1];                   
        }
    }
    
    return Result;                                                          
}

Polynomial Polynomial::getIndefiniteIntegral() const
{
    Polynomial Result;                                                      
    
    Result.fDegree = fDegree + 1;                                          
    
    for ( size_t i = 1; i <= fDegree + 1; i++ )                             
    {
        Result.fCoeffs[i] = fCoeffs[i - 1] / i;                             
    }
    
    return Result;                                                         
}

double Polynomial::getDefiniteIntegral( double aXLow, double aXHigh ) const
{
    Polynomial lIndefiniteIntegral = getIndefiniteIntegral();               
    
    return lIndefiniteIntegral( aXHigh ) - lIndefiniteIntegral( aXLow );    
}
                                                                            