#include "main.hpp"
#include <cmath>
#include <cstdio>

std::vector<point> coordinates;
std::vector<std::vector<unsigned long long>> distances;
std::vector<int> callCounts;

#define sq( a ) ( ( a ) * ( a ) )
#define x( idx ) ( callCounts[ idx ] ? ( coordinates[ idx ].x / callCounts[ idx ] ) : coordinates[ idx ].x )
#define y( idx ) ( callCounts[ idx ] ? ( coordinates[ idx ].y / callCounts[ idx ] ) : coordinates[ idx ].y )
void calculatePositions( int p_p1, int p_p2 )
{
    double xs = x( p_p1 );
    double ys = y( p_p1 );
    double xr = x( p_p2 );

    unsigned long long d = distances[ p_p1 ][ p_p2 ];

    double yr = ( ( coordinates[ p_p2 ].y + sqrt( sq( d ) - sq( xr - xs ) + ys ) ) / ++callCounts[ p_p2 ] ) ;
    coordinates[ p_p2 ].x += xr;

    for( int m = 0; m < (int)coordinates.size( ); ++m ) {
        if( m == p_p1 || m == p_p2 ) continue;

        unsigned long long e = distances[ p_p1 ][ m ];
        unsigned long long f = distances[ p_p2 ][ m ];

        coordinates[ m ].x += ( sq( f ) - sq( e ) + sq( xs ) - sq( xr ) ) / ( 2 * ( xs - xr ) );
        coordinates[ m ].y += ( sq( f ) - sq( e ) + sq( ys ) - sq( yr ) ) / ( 2 * ( ys - yr ) );

        callCounts[ m ]++;
    }
};

void getPointCount( ) {
    printf("update\r\n");

    size_t pointCount;

    coordinates.assign( pointCount, { 0, 0 } );
    distances.assign( pointCount, std::vector<unsigned long long>(pointCount,0) );
}
