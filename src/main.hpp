#include <vector>

struct point{
    double x, y;
};

extern std::vector<point> coordinates;
extern std::vector<std::vector<unsigned long long>> distances; //Distances in μm

void getPointCount( );
void getDistance( int p_pt1idx, int p_pt2idx );

void calculatePositions( int p_pt1idx, int p_pt2idx );
