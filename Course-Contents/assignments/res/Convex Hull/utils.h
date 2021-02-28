# include "stdio.h"
// data structures
typedef struct Point
{
    int x;
    int y;
} Point;

// signatures
Point newPoint(int x, int y);

void printPoint(Point pt);