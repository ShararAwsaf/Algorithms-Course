#include "stdio.h"
#include "stdlib.h"

#include "utils.h"

// function headers
Point* computeConvexHullPts(Point* ptArr, int length, int* hullLength);
Point* computeQuickHullPts(Point* pointArr, int length, int* hullLength);
void recurseTriangleBuild(Point* pointArray, int* length, Point leftMost, Point rightMost, Point* convexHullArray, int* hullLength);

void testBruteForceConvexHull();
void testQuickHull();
void testArrayDeletion();
void testDistToPtFromLine();

Point* computeConvexHullPts(Point* ptArr, int length, int* hullLength)
{

    Point* copyPtArr = copyPointArray(ptArr, length); // making a copy to preserve ordering of original set of points
    Point* convexHullPtArr = malloc(sizeof(Point)*length);

    // printf("Starting Convex Hull Brute Force\n");
    // printPointArray(ptArr, length);

    // sort points based on increasing x and y
    bubbleSort(copyPtArr, length);
    // printf("Finished Sorting");
    // printPointArray(copyPtArr, length);
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
        // printf("More than 2 points found\n");
        Point initialHullPt = copyPtArr[0];
        int hullIndex = 0;
        // printf("Storing Left most\n");
        convexHullPtArr[hullIndex] = initialHullPt; // the leftMost point is a part of convex hull set
        // printf("Starting Iterations\n");
        for(int i=1; ; )
        {
            Point nextHullPt = copyPtArr[i]; // assume the next point to be a hull point
            for(int checkingIndex = i; checkingIndex < length; checkingIndex++)
            {
                Point checkHullPt = copyPtArr[checkingIndex];

                // for every point from 3rd onwards check hull condition : cross product of vectors less than zero
                Point vector1 = createVector(nextHullPt, initialHullPt);
                Point vector2 = createVector(checkHullPt, initialHullPt);

                // printf("VECTOR 1\n");
                // printPoint(vector1);

                // printf("VECTOR 2\n");
                // printPoint(vector2);

                int z = crossProduct(vector2, vector1);
                // printf("Cross Product : %d\n", z);

                if(z<0)
                {
                    nextHullPt = checkHullPt;
                }
            }
            if( pointEquals(nextHullPt ,convexHullPtArr[0])) // finished roundtrip
            {
                // printf("Completed Round Trip\n");
                break;
            }
            else 
            {
                hullIndex++;
                convexHullPtArr[hullIndex] = nextHullPt;
                // printf("HULL POINT:\n");
                // printPoint(nextHullPt);
                initialHullPt = nextHullPt;
                i = 0; // assume the leftmost as the hull point from current hull (will always be false so a safe initialization case)
                // printf("******************************\n");
            }
        }
        // adjust the hull size for reporting
        (*hullLength) = hullIndex+1;

    }
    free(copyPtArr);
    return convexHullPtArr;

}

// QUICK HULL



void recurseTriangleBuild(Point* pointArray, int* length, Point leftMost, Point rightMost, Point* convexHullArray, int* hullLength)
{   
    // Base Case
    if((*length) == 0)
    {
        printf("Returning From Recursion since no points exist\n");
        return;
    }


    printf("Recursive Entry Src size %d", (*length));
    printPointArray(pointArray, (*length));
    printf("LEFTMOST POINT\n");
    printPoint(leftMost);
    printf("RIGHTMOST POINT\n");
    printPoint(rightMost);

    // Determine Farthest Point to Include as HULL POINT
    int hullIndex = (*hullLength);

    int farthestFirstHalfIndex = getMaxDistancePointFromLine(leftMost, rightMost, pointArray, (*length));
    Point farthestPoint = pointArray[farthestFirstHalfIndex];
    convexHullArray[hullIndex++] = newPoint(farthestPoint.x, farthestPoint.y);
    removeIndexFromPointArray(pointArray, length, farthestFirstHalfIndex);
    (*hullLength) = hullIndex;
    printf("FARTHEST POINT >> Entering Hull...\n");
    printPoint(farthestPoint);

    // Split Points based on orientation
    int topLength = (*length);
    Point* topPoints = malloc(sizeof(Point)*topLength);
    int t = 0;

    int bottomLength = (*length);
    Point* bottomPoints = malloc(sizeof(Point)*bottomLength);
    int b = 0;

    for(int i=0; i<(*length); i++)
    {   
        // int topOrient = determineOrientation(leftMost, farthestPoint, pointArray[i]);
        // int bottomOrient = determineOrientation(farthestPoint, rightMost, pointArray[i]);
        // printf("ORIENT TOP %d | ORIENT BOTTOM %d\n", topOrient, bottomOrient);

        int trPt = isPointInTriangle(rightMost, leftMost, farthestPoint, pointArray[i]);
        printf("IN TRIANGLE %d\n", trPt);
        if(!trPt)
        {
            float distLF = distanceLineToPoint(leftMost, farthestPoint, pointArray[i]);
            float distFR = distanceLineToPoint(farthestPoint, rightMost, pointArray[i]);
            if( distLF < distFR)
            {
                // printf("TOP ORIENT: %d | ", topOrient);
                printf("INSERTING TOP...\n");
                printPoint(pointArray[i]);
                topPoints[t++] = newPoint(pointArray[i].x, pointArray[i].y);
                bottomLength--;
            }
            else // if(bottomOrient == BOTTOM)
            {
                // printf("BOTTOM ORIENT: %d | ", bottomOrient);
                printf("INSERTING BOTTOM...\n");
                printPoint(pointArray[i]);
                bottomPoints[b++] = newPoint(pointArray[i].x, pointArray[i].y);
                topLength--;
            }
        }
        else
        {
            printf("Skipping point....\n");
            printPoint(pointArray[i]);
            topLength--;
            bottomLength--;
        }
        
    }

    printf("First Subset of size %d\n", topLength);
    printPointArray(topPoints, topLength);

    printf("Second Subset of size %d\n", bottomLength);
    printPointArray(bottomPoints, bottomLength);


    printf("Before Recursion Hull of Size %d\n", (*hullLength));
    printPointArray(convexHullArray, (*hullLength));


    recurseTriangleBuild(topPoints, &topLength, leftMost, farthestPoint, convexHullArray, hullLength);
    recurseTriangleBuild(bottomPoints, &bottomLength, farthestPoint, rightMost, convexHullArray, hullLength);
    
    printf("After Recursion Hull of Size %d\n", (*hullLength));
    printPointArray(convexHullArray, (*hullLength));

}




Point* computeQuickHullPts(Point* pointArr, int length, int* hullLength)
{
    Point* copyPtArr = copyPointArray(pointArr, length); // making a copy to preserve ordering of original set of points
    Point* convexHullPtArr = malloc(sizeof(Point)*length);

    // sort points based on increasing x and y
    bubbleSort(copyPtArr, length);

    printf("After sorting source copy of size %d\n", length);
    printPointArray(copyPtArr, length);

    Point leftMost = copyPtArr[0];
    Point rightMost = copyPtArr[length-1];
    
    int hullIndex = 0;

    convexHullPtArr[hullIndex++] = newPoint(leftMost.x, leftMost.y);
    int leftIndex = 0;
    removeIndexFromPointArray(copyPtArr, &length, leftIndex);
    printf("Deleted Index %d, src current size %d\n", leftIndex, length);
    printPointArray(copyPtArr, length);

    convexHullPtArr[hullIndex++] = newPoint(rightMost.x, rightMost.y);
    int rightIndex = length-1;
    removeIndexFromPointArray(copyPtArr, &length, rightIndex);
    printf("Deleted Index %d, src current size %d\n", rightIndex, length);
    printPointArray(copyPtArr, length);

    (*hullLength) = hullIndex;
    printf("Printing Hull of Size %d\n", (*hullLength));
    printPointArray(convexHullPtArr, (*hullLength));

    // find two sets of points BASED ON THE TWO SIDES OF leftMost and rightMost POINTS
    int topLength = length;
    Point* topPoints = malloc(sizeof(Point)*topLength);
    int t = 0;

    int bottomLength = length;
    Point* bottomPoints = malloc(sizeof(Point)*bottomLength);
    int b = 0;
    for(int i=0; i<length; i++)
    {   
        int orient = determineOrientation(leftMost, rightMost, copyPtArr[i]);
        printf("INIT ORIENT: %d | ", orient);
        if( orient == BOTTOM)
        {
            printf("INSERTING TOP...\n");
            printPoint(copyPtArr[i]);
            topPoints[t++] = newPoint(copyPtArr[i].x, copyPtArr[i].y);
            bottomLength--;
        }
        else if(orient == TOP)
        {
            printf("INSERTING BOTTOM...\n");
            printPoint(copyPtArr[i]);
            bottomPoints[b++] = newPoint(copyPtArr[i].x, copyPtArr[i].y);
            topLength--;
        }
        else
        {
            printf("Skipping point....\n");
            printPoint(copyPtArr[i]);
            topLength--;
            bottomLength--;
        }
        
    }

    printf("Init First Subset of size %d", topLength);
    printPointArray(topPoints, topLength);

    printf("Init Second Subset of size %d\n", bottomLength);
    printPointArray(bottomPoints, bottomLength);

    recurseTriangleBuild(topPoints, &topLength, leftMost, rightMost, convexHullPtArr, hullLength);
    recurseTriangleBuild(bottomPoints, &bottomLength, leftMost, rightMost, convexHullPtArr, hullLength);


    free(copyPtArr);
    return convexHullPtArr;
}


int main()
{
    int length = 0;
    Point* inputArr = getPointArray(&length);
    // printf("GIVEN SET\n");
    // bubbleSort(inputArr, length);
    // printPointArray(inputArr, length);

    testBruteForceConvexHull(inputArr, length);
    // testQuickHull(inputArr, length);

    return 0;
}

void testQuickHull(Point* givenArr, int len)
{
    int length = givenArr == NULL ? 0 : len;
    Point* ptArr = givenArr == NULL ? getPointArray(&length) : givenArr;

    int hullLength = 0;
    Point* hullPtArr = computeQuickHullPts(ptArr, length, &hullLength);

    printf("Printing Sorted Hull of size %d", hullLength);
    bubbleSort(hullPtArr, hullLength);
    printPointArray(hullPtArr, hullLength);
    
    
    // release memory
    // free(ptArr);
    // free(hullPtArr);
}


void testBruteForceConvexHull(Point* givenArr, int len)
{
    
    int length = givenArr == NULL ? 0 : len;
    Point* ptArr = givenArr == NULL ? getPointArray(&length) : givenArr;

    // get set of input points
    int hullLength = 0;
    Point* hullPtArr = computeConvexHullPts(ptArr, length, &hullLength);
    printf("Expected Length : %d\n", hullLength);
    bubbleSort(hullPtArr, hullLength);
    printPointArray(hullPtArr, hullLength);

    // release memory
    free(ptArr);
    free(hullPtArr);
}

void testArrayDeletion()
{
    int length = 0;
    Point* ptArr = getStaticPointArray(&length);

    printPointArray(ptArr, length);
    int delIndex = 0;
    removeIndexFromPointArray(ptArr, &length, delIndex);
    printf("After Deleting Index %d\n", delIndex);
    printPointArray(ptArr, length);

    // release memory
    free(ptArr);
}


void testDistToPtFromLine()
{
    Point p1 = newPoint(4, 5);
    Point p2 = newPoint(7, 8);
    Point d = newPoint(2, 6);

    float r = distanceLineToPoint(p1, p2, d);


    printf("Line Points\n");
    printPoint(p1);
    printPoint(p2);

    printf("Given Point\n");
    printPoint(d);

    printf("Distance : %f\n", r);
}