#include "stdio.h"
#include "stdlib.h"

#include "utils.h"


Point* computeConvexHullPts(Point* ptArr, int length, int* hullLength)
{

    Point* copyPtArr = copyPointArray(ptArr, length); // making a copy to preserve ordering of original set of points
    Point* convexHullPtArr = malloc(sizeof(Point)*length);

    printf("Starting Convex Hull Brute Force\n");
    printPointArray(ptArr, length);

    // sort points based on increasing x and y
    bubbleSort(copyPtArr, length);
    printf("Finished Sorting");
    printPointArray(copyPtArr, length);
    // if only two points then both will be part of convex hull
    if(length <= 2)
    {
        for(int i=0; i<length; i++)
        {
            convexHullPtArr[i] = copyPtArr[i];
        }
        
    }
    else
    {
        printf("More than 2 points found\n");
        Point initialHullPt = copyPtArr[0];
        int hullIndex = 0;
        printf("Storing Left most\n");
        convexHullPtArr[hullIndex] = initialHullPt; // the leftMost point is a part of convex hull set
        printf("Starting Iterations\n");
        for(int i=1; ; )
        {
            Point nextHullPt = copyPtArr[i]; // assume the next point to be a hull point
            for(int checkingIndex = i; checkingIndex < length; checkingIndex++)
            {
                Point checkHullPt = copyPtArr[checkingIndex];

                // for every point from 3rd onwards check hull condition : cross product of vectors less than zero
                Point vector1 = createVector(nextHullPt, initialHullPt);
                Point vector2 = createVector(checkHullPt, initialHullPt);

                printf("VECTOR 1\n");
                printPoint(vector1);

                printf("VECTOR 2\n");
                printPoint(vector2);

                int z = crossProduct(vector2, vector1);
                printf("Cross Product : %d\n", z);

                if(z<0)
                {
                    nextHullPt = checkHullPt;
                }
            }
            if( pointEquals(nextHullPt ,convexHullPtArr[0])) // finished roundtrip
            {
                printf("Completed Round Trip\n");
                break;
            }
            else 
            {
                hullIndex++;
                convexHullPtArr[hullIndex] = nextHullPt;
                printf("HULL POINT:\n");
                printPoint(nextHullPt);
                initialHullPt = nextHullPt;
                i = 0; // assume the leftmost as the hull point from current hull (will always be false so a safe initialization case)
                printf("******************************\n");
            }
        }
        // adjust the hull size for reporting
        (*hullLength) = hullIndex+1;

    }
    free(copyPtArr);
    return convexHullPtArr;

}


int main()
{
    int length = 0;
    Point* ptArr = getPointArray(&length);
    // get set of input points

    int hullLength = 0;
    Point* hullPtArr = computeConvexHullPts(ptArr, length, &hullLength);
    printPointArray(hullPtArr, hullLength);

    // release memory
    free(ptArr);
    free(hullPtArr);
    return 0;
}