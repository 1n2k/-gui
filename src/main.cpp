#include "main.hpp"
#include "bitmap.h"
#include <cstdio>
#include <cstdlib>

std::vector<point> coordinates;
std::vector<std::vector<unsigned long long> > distances;


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
    bitmap image = bitmap( 450, 450 );
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
