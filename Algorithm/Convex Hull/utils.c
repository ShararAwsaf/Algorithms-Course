# include "utils.h"

Point newPoint(int x, int y)
{
    Point pt;

    pt.x = x;
    pt.y = y;

    return pt;
}

void printPoint(Point pt)
{
    printf("X : %d\n", pt.x);
    printf("Y : %d\n", pt.y);

}

void printPointArray(Point* ptArray, int len)
{
    for(int i=0; i<len; i++)
    {
        printf("\n%d\n", i+1);
        printPoint(ptArray[i]);
    }
}

int pointEquals(Point p1, Point p2)
{
    return (p1.x == p2.x) && (p1.y == p2.y);
}

Point* getPointArray(int* lenPtr)
{
    int len = POINTS;
    Point* ptArray = malloc(sizeof(Point)* len);
    int numLimit = RAND;
    for(int i=0; i<len; i++)
    {
        ptArray[i] = newPoint(rand()%numLimit, rand()%numLimit);
    }

    (*lenPtr) = len;
    return ptArray;
}


Point* getStaticPointArray(int* lenPtr)
{
    int len = 5;
    Point* ptArray = malloc(sizeof(Point)* len);

    ptArray[0] = newPoint(10,0);
    ptArray[1] = newPoint(0,10);
    ptArray[2] = newPoint(0,0);
    ptArray[3] = newPoint(10,10);
    ptArray[4] = newPoint(5,5);


    (*lenPtr) = len;
    return ptArray;

}


Point* copyPointArray(Point* ptArray, int len)
{
    Point* copyPtArray = malloc(sizeof(Point)*len);

    for(int i=0; i<len; i++)
    {
        copyPtArray[i] = newPoint(ptArray[i].x, ptArray[i].y);
    }
    return copyPtArray;
}

void removeIndexFromPointArray(Point* ptArray, int* length, int index)
{
    if(index >= (*length) || index < 0)
        return;

    for(int i = 0; i<(*length); i++)
    {
        if(i >= index && i+1 < (*length))
        {
            ptArray[i] = ptArray[i+1];
        }
    }

    (*length) = (*length)-1;
    return;
}

Point createVector(Point p1, Point p2)
{
    return newPoint(p1.x-p2.x, p1.y-p2.y);
}

int crossProduct(Point p1, Point p2)
{
    return (p1.x * p2.y) - (p2.x * p1.y);
}


float distanceLineToPoint(Point lpt1, Point lpt2, Point dPt)
{
    float result = 0.0;

    int a = (lpt1.y - lpt2.y);
    int b = (lpt2.x - lpt1.x);
    int c = (lpt1.x * lpt2.y) - (lpt2.x * lpt1.y);

    int a_sq = a * a;
    int b_sq = b * b;
    
    float denom = sqrtf( a_sq + b_sq  );
    int numer = (a * dPt.x) + (b * dPt.y) + c;

    result = (float)numer / denom;

    if(result < 0)
        result = result * -1;

    return result;
}

int isPointInTriangle(Point trLeft, Point trRight, Point trTop, Point p)
{
    float T = getTriangleArea(trLeft, trRight, trTop);
    float A1 = getTriangleArea(trLeft, trRight, p);
    float A2 = getTriangleArea(trLeft, p, trTop);
    float A3 = getTriangleArea(p, trRight, trTop);

    if(A1 + A2 + A3 > T)
        return FALSE;
    
    return TRUE;
}

float getTriangleArea(Point p1, Point p2, Point p3)
{
    float result = ( p1.x * (p2.y - p3.y) ) - ( p2.x * (p1.y - p3.y) ) + ( p3.x * (p1.y - p2.y) );
    if(result < 0)
        result = result * -1;
    return 0.5 * result;
}

int getMaxDistancePointFromLine(Point leftMost, Point rightMost, Point* pointArray, int length)
{
    int farthestIndex = -1;
    float maxDist = -1;    
    for(int i=0; i<length; i++)
    {
        float currDist = distanceLineToPoint(leftMost, rightMost, pointArray[i]);
        if(currDist > maxDist)
        {
            maxDist = currDist;
            farthestIndex = i;
        }
    }

    return farthestIndex;
}

int determineOrientation(Point lp1, Point lp2, Point p)
{
    // (y-y1) = [(y1-y2)/(x1-x2)](x-x1)

    int orient = ((p.y - lp1.y)*(lp1.x - lp2.x))-((lp1.y-lp2.y)*(p.x-lp1.x));

    if (orient < 0)
        return BOTTOM;
    
    if(orient > 0)
        return TOP;
    
    
    return IGNORE;
}


void bubbleSort(Point* ptArray, int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len ; j++)
        {
            if( (ptArray[j].x < ptArray[i].x) || (ptArray[j].x == ptArray[i].x && ptArray[j].y < ptArray[i].y))
            {
                Point tmp = ptArray[i];
                ptArray[i] = ptArray[j];
                ptArray[j] = tmp;
            }
            
        }
    }

}

