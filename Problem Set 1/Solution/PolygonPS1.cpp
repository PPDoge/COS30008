#include "Polygon.h"
 
using namespace std;

float Polygon::getSignedArea() const
{
    float Result = 0.0f;                                               

    if ( fNumberOfVertices > 2 )                                        
    {
        for ( size_t i = 1; i < fNumberOfVertices; i++ )                
        {
            Vector2D v0 = fVertices[i - 1];                             
            Vector2D v1 = fVertices[i];                                 
            Result += v0.getX() * v1.getY() - v0.getY() * v1.getX();    
        }

        Vector2D v0 = fVertices[fNumberOfVertices - 1];                 
        Vector2D v1 = fVertices[0];                                     
        Result += v0.getX() * v1.getY() - v0.getY() * v1.getX();        
    }

    return Result / 2.0f;                                              
}                                                                     

