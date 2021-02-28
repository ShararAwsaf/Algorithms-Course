/**
 * Name: Sharar Mahmood
 * Id: 0955835
 * Date: 6 Feb 2021
 * Assignment: A2
 * **/

# include "utils.h"
# include <sys/timeb.h>

# define MAX_POINT_COUNT 30000

typedef struct point
{
    double x;
    double y;
} Point;

// helpers
// print point
void printPoint(Point pt);

// print array of points
void printPointArray(Point* points, int pointCount);

// Creates array of points from strings representing pair of points
void createPointArrayFromStrings(Point* pointArray, int* pointCount, char** strings, int stringCount, char* separator);

// sorts using brute force an array of points
void sortPoints(Point* points, int pointCount);

// searches exhaustively for a point in a list
int exhaustiveSearchPoints(Point* points, int pointCount, Point searchPoint);

// insert a point to a list if its unique
void insertUniquePoint(Point* points, int* pointCount, Point insertPoint);

// math helpers
// square of distance between two points
double distSquare(Point p1, Point p2);

// determine which side a point is with respect to a line given line end points
int signOfPointWithRespectToLine(Point p1, Point p2, Point inputPt);

// determine which side a point is with respect to a line given line coefficients
int signOfPointWithRespectToLineCoeffs(double a, double b, double c, Point inputPt);

// driver of brute force convex hull
void p21(char** lines, int lineCount);

// brute force convex hull
void convexHullBruteForce(Point* points, int pointCount, Point* hull, int* hullSize);