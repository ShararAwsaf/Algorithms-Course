#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define RAND 200
#define POINTS 200
#define TRUE 1
#define FALSE 0
#define TOP 1
#define BOTTOM -1
#define IGNORE 0

// data structures
typedef struct Point
{
    int x;
    int y;
} Point;

// signatures
Point newPoint(int x, int y);
void printPoint(Point pt);
int pointEquals(Point p1, Point p2);


void printPointArray(Point* ptArray, int len);
Point* getPointArray(int* lenPtr);
Point* getStaticPointArray(int* lenPtr);
Point* copyPointArray(Point* ptArray, int len);
void removeIndexFromPointArray(Point* ptArray, int* length, int index);
int determineOrientation(Point lp1, Point lp2, Point p);

Point createVector(Point p1, Point p2);
int crossProduct(Point p1, Point p2);

float distanceLineToPoint(Point lpt1, Point lpt2, Point dPt);
int isPointInTriangle(Point trLeft, Point trRight, Point trTop, Point p);
float getTriangleArea(Point p1, Point p2, Point p3);
int getMaxDistancePointFromLine(Point leftMost, Point rightMost, Point* pointArray, int length);


void bubbleSort(Point* ptArray, int len);