#include "stdio.h"
#include "stdlib.h"

#define POINTS 100

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
Point* copyPointArray(Point* ptArray, int len);


Point createVector(Point p1, Point p2);
int crossProduct(Point p1, Point p2);





void bubbleSort(Point* ptArray, int len);