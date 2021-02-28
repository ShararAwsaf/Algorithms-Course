# include "utils.h"

# define MAX_POINT_COUNT 30000

typedef struct point
{
    double x;
    double y;
} Point;

// helpers
void printPoint(Point pt);
void printPointArray(Point* points, int pointCount);
void createPointArrayFromStrings(Point* pointArray, int* pointCount, char** strings, int stringCount, char* separator);
void sortPoints(Point* points, int pointCount);
int exhaustiveSearchPoints(Point* points, int pointCount, Point searchPoint);
void insertUniquePoint(Point* points, int* pointCount, Point insertPoint);

// math helpers
double distSquare(Point p1, Point p2);
int signOfPointWithRespectToLine(Point p1, Point p2, Point inputPt);

// main
void p21(char** lines, int lineCount);
void convexHullBruteForce(Point* points, int pointCount);