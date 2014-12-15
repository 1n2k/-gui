#include "main.hpp"
#include <cstdio>

std::vector<point> coordinates;
std::vector<std::vector<unsigned long long>> distances;


point crystal_meth_ods(point s, double xr, int d, int e, int f)
{
    double yr = math.sqrt(math.pow(d,2)-math.pow(xr-s.x,2)+s.y);
    double xm = ((math.pow(f,2)-math.pow(e,2))+(math.pow(s.x,2)-math.pow(xr,2))/(2*(s.x-xr));
    double ym = ((math.pow(f,2)-math.pow(e,2))+(math.pow(s.y,2)-math.pow(yr,2))/(2*(s.y-yr));
    return {xm, ym};
};

void getPointCount( ) {
    printf("update\r\n");

    size_t pointCount;

    coordinates.assign( pointCount, { 0, 0 } );
    distances.assign( pointCount, std::vector<unsigned long long>(pointCount,0) );
}
