#include "stdio.h"
#include "stdlib.h"

#include "utils.h"

Point* getPointArray(int* lenPtr)
{
    int len = 10;
    Point* ptArray = malloc(sizeof(Point)* len);

    for(int i=0; i<len; i++)
    {
        ptArray[i] = newPoint(rand(), rand());
    }

    (*lenPtr) = len;
    return ptArray;
}

void printPointArray(Point* ptArray, int len)
{
    for(int i=0; i<len; i++)
    {
        printf("\n%d\n", i+1);
        printPoint(ptArray[i]);
    }
}

int main()
{

    int length = 0;
    Point* ptArr = getPointArray(&length);

    printPointArray(ptArr, length);    

    return 0;
}