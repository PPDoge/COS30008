#include "Combination.h"

Combination::Combination( size_t aN, size_t aK ) :
    fN(aN),                                                       
    fK(aK)                                                          
{}

size_t Combination::getN() const
{
    return fN;                                                      
}

size_t Combination::getK() const
{
    return fK;                                                    
}

unsigned long long Combination::operator()() const
{
    if ( fK > fN )                                                  
    {
        return 0;                                                  
    }
    else
    {
        unsigned long long Result = 1;                              

        for ( unsigned long long i = 0; i < fK; )                   
        {
            Result *= (fN - i);                                     
            Result /= ++i;                                          
        }

        return Result;                                              
    }
}                                                                   
