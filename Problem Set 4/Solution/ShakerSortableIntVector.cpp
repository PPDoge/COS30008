#include "ShakerSortableIntVector.h"

ShakerSortableIntVector::ShakerSortableIntVector( const int aArrayOfIntegers[], size_t aNumberOfElements ) :
    SortableIntVector( aArrayOfIntegers, aNumberOfElements )                    
{}

void ShakerSortableIntVector::sort( Comparable aOrderFunction )
{
    size_t lBeginIndex = 0;                                                    
    size_t lEndIndex = size() - 1;                                             
        
        while ( lBeginIndex < lEndIndex )                                       
        {
            for ( size_t i = lBeginIndex; i < lEndIndex; i++ )                  
            {
                if ( aOrderFunction( get( i ), get( i + 1 ) ) )                
                {
                    swap( i, i + 1 );                                           
                }
            }
            
            lEndIndex--;                                                       

            for ( size_t i = lEndIndex; i > lBeginIndex; i-- )                  
            {
                if ( aOrderFunction( get( i - 1 ), get( i ) ) )                 
                {
                    swap( i - 1, i );                                           
                }
            }
            
            lBeginIndex++;                                                     
        }                                                                       
}                                                                              
