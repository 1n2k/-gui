#include "main.hpp"
#include <cstdio>

std::vector<point> coordinates;
std::vector<std::vector<unsigned long long>> distances;

void getPointCount( ) {
    printf("update\r\n");

    size_t pointCount;

    coordinates.assign( pointCount, { 0, 0 } );
    distances.assign( pointCount, std::vector<unsigned long long>(
