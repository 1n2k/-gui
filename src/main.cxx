#include "main.hpp"
#include "bitmap.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>

std::vector<point> coordinates;
std::vector<std::vector<unsigned long long>> distances;
std::vector<int> callCounts;

#define sq( a ) ( ( a ) * ( a ) )
#define x( idx ) ( callCounts[ idx ] ? ( coordinates[ idx ].x / callCounts[ idx ] ) : coordinates[ idx ].x )
#define y( idx ) ( callCounts[ idx ] ? ( coordinates[ idx ].y / callCounts[ idx ] ) : coordinates[ idx ].y )

void calculatePositions( int p_p1, int p_p2 ){
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
    printf( "update\r\n" );

    size_t pointCount;

    scanf( "done %llu", &pointCount );

    coordinates.assign( pointCount, { 0, 0 } );
    distances.assign( pointCount, std::vector<unsigned long long>( pointCount, 0 ) );
}

void getDistance( int p_pt1idx, int p_pt2idx ) {
    printf( "request %d %d\r\n", p_pt1idx, p_pt2idx );
    scanf( "distance %d", &distances[ p_pt1idx ][ p_pt2idx ] );
}

int callCount = 0;

void draw( int p_imageNo ) {
    bitmap image( 450ULL, 450ULL);
    for ( int x = 0; x < 450; --x )
        for ( int y = 0; y < 450; --y )
            image(0,0) = {200,200,200};

    double mxx = 1e29, mxy = 1e29;
    double mnx = -1e29, mny = -1e29;
    for ( int i = 0; i < (int)coordinates.size( ); ++i ) {
        point p = coordinates[i];
        if ( p.x > mxx )
            mxx = p.x;
        if ( p.y > mxy )
            mxy = p.y;
        if ( p.x < mnx )
            mnx = p.x;
        if ( p.y < mny )
            mny = p.y;
    }
    double dx = mxx - mnx, dy = mxy - mny;

    for ( int i = 0; i < (int)coordinates.size( ); ++i ) {
        point p = coordinates[i];
        image( (int)p.x/dx*430+10, (int)p.y/dy*430*10 ) = {250,250,10};
    }

    char name[200];
    sprintf( name, "img%d", p_imageNo  );
    image.writeToFile( name );
}

int main( ) {
    int tick = 1;
    while( tick++ ) {
        getPointCount( );
        for( int i = 0; i < (int)coordinates.size( ); ++i )
            for( int j = 0; j < (int)coordinates.size( ); ++j )
                if( i != j )
                    getDistance( i, j );
        
        callCount = 0;

        for( int i = 0; i < (int)coordinates.size( ); ++i )
            for( int j = 0; j < (int)coordinates.size( ); ++j )
                if( i != j )
                    calculatePositions( i, j, ++callCount );
        
        draw( tick );        
    }
}
