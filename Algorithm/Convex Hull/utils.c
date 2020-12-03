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
    int numLimit = 50;
    for(int i=0; i<len; i++)
    {
        ptArray[i] = newPoint(rand()%numLimit, rand()%numLimit);
    }

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

Point createVector(Point p1, Point p2)
{
    return newPoint(p1.x-p2.x, p1.y-p2.y);
}

int crossProduct(Point p1, Point p2)
{
    return (p1.x * p2.y) - (p2.x * p1.y);
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