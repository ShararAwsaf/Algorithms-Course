/**
 * Name: Sharar Mahmood
 * Id: 0955835
 * Date: 6 Feb 2021
 * Assignment: A2
 * **/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <sys/timeb.h>
#include "utils.h"

# define MAX_POINT_COUNT 30000

typedef struct Pt
{
    double x;
    double y;
} Pt;

// top level code for running and printing using quick hull
void p22(char** lines, int lineCount);

// Creates array of points from strings representing pair of points
void createPointArrayFromStringsQuickHull(Pt* pointArray, int* pointCount, char** strings, int stringCount, char* separator);


// old code 
#define RAND 200
#define POINTS 200
#define TRUE 1
#define FALSE 0
#define TOP 1
#define BOTTOM -1
#define IGNORE 0

// utils
// data structures

// signatures

// create new point
Pt newPoint(double x, double y);

// print point
void printPointQuickHull(Pt pt);

// compare two points
int pointEquals(Pt p1, Pt p2);

// print array of points
void printPointArrayQuickHull(Pt* ptArray, int len);

// create copy of array of points
Pt* copyPointArray(Pt* ptArray, int len);

// remove point from array of points
void removeIndexFromPointArray(Pt* ptArray, int* length, int index);

// determine which side of a line the point lies
int determineOrientation(Pt lp1, Pt lp2, Pt p);

// calculate distance of point to line
double distanceLineToPoint(Pt lpt1, Pt lpt2, Pt dPt);

// check if a point is in a triangle
int isPointInTriangle(Pt trLeft, Pt trRight, Pt trTop, Pt p);

// compute triangle area
double getTriangleArea(Pt p1, Pt p2, Pt p3);

// given a set of points and a line find the farthest point from that line
int getMaxDistancePointFromLine(Pt leftMost, Pt rightMost, Pt* pointArray, int length);

// sorts using brute force an array of points
void bubbleSort(Pt* ptArray, int len);

// compute quick hull
Pt* computeQuickHullPts(Pt* pointArr, int length, int* hullLength);

// subroutine for partitioning the points in quick hull computation
void recurseTriangleBuild(Pt* pointArray, int* length, Pt leftMost, Pt rightMost, Pt* convexHullArray, int* hullLength);

// find squared of line length
double lineLengthSq(Pt p1, Pt p2);

// the difference of x coordinates of two points
double xDist(Pt p1, Pt p2);

// check if a third point is in between x axis of two given points
int inBetweenX(Pt p1, Pt p2, Pt p);

// subroutine performing the merge operations of two sorted array of points
void mergePtArrays(int s, int m, int e, Pt* A);

// subroutine dividing a set of points to two sets of equal or almost equal sizes
void splitPtArray(int s, int e, Pt* A);

// sorts points using divide and conquer
void mergeSort(Pt* intArray, int intCount);

// old code