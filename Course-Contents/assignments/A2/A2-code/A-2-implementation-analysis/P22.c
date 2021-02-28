/**
 * Name: Sharar Mahmood
 * Id: 0955835
 * Date: 6 Feb 2021
 * Assignment: A2
 * **/

# include "P22.h"

void p22(char** lines, int lineCount)
{
    Pt points[MAX_POINT_COUNT];
    int pointCount = -1;

    createPointArrayFromStringsQuickHull(points, &pointCount, lines, lineCount, " ");
    // printPointArray(points, pointCount);
    // printf("SORTED\n");

    // Sort points to ensure starting from extreme point
    // sortPoints(points, pointCount);
    // printPointArray(points, pointCount);

    struct timeb startTime;
    struct timeb endTime;
    
    ftime(&startTime);
    int hullSize = 0;
    Pt* hull = computeQuickHullPts(points, pointCount, &hullSize);
    ftime(&endTime);
    // bubbleSort(hull, hullSize);
    mergeSort(hull, hullSize);
    printPointArrayQuickHull(hull, hullSize);
    printf("CONVEX HULL SIZE: %d\n", hullSize);
    int runTime = (int) (1000.0 * (endTime.time - startTime.time) + (endTime.millitm - startTime.millitm)); 
    printf("Running Time (ms): %d\n", runTime);
}

void createPointArrayFromStringsQuickHull(Pt* pointArray, int* pointCount, char** strings, int stringCount, char* separator)
{
    (*pointCount) = stringCount;
    int index = 0;

    for(int i=0; i<stringCount; i++)
    {
        char* token = strtok(strings[i], separator);
        int turn = 1;
        while(token != NULL)
        {
            double coordinate = atof(token);

            // if (coordinate > 0.0)
            // {
                if(turn == 1)
                {
                    pointArray[index].x = coordinate;
                    turn = 2;
                }
                else
                {
                    pointArray[index].y = coordinate;
                    turn  = 1;
                }
            // }

            // printf("%d\n", intArray[index]);
            token = strtok(NULL, separator);
        }
        index += 1;
    }
}

// old code

// utils
void bubbleSort(Pt* ptArray, int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len ; j++)
        {
            if( (ptArray[j].x < ptArray[i].x) || (ptArray[j].x == ptArray[i].x && ptArray[j].y < ptArray[i].y))
            {
                Pt tmp = ptArray[i];
                ptArray[i] = ptArray[j];
                ptArray[j] = tmp;
            }
            
        }
    }
}

void splitPtArray(int s, int e, Pt* A)
{
    if (s == e-1)
    {
        return;
    }

    int m = (s+e) / 2;
    
    splitPtArray(s, m, A);
    splitPtArray(m, e, A);

    mergePtArrays(s, m, e, A);

}

void mergePtArrays(int s, int m, int e, Pt* A)
{
    int l = s;
    int r = m;
    int k = 0;
    Pt sortedSubarray[MAX_POINT_COUNT];

    Pt smallerNumber = A[0];

    while (l<m && r<e)
    {
        if ((A[l].x > A[r].x) || ( A[l].x == A[r].x && A[l].y > A[r].y))
        {
            smallerNumber = A[r];
            r += 1;
        }
        else
        {
            smallerNumber = A[l];
            l += 1;
        }
        sortedSubarray[k] = smallerNumber;
        k += 1;
    }

    
    while (l < m)
    {
        sortedSubarray[k] = A[l];
        l += 1;
        k += 1;
    }

    while (r < e)
    {
        sortedSubarray[k] = A[r];
        r += 1;
        k += 1;
    }

    // Sort the subarray A[s:e]
    k = 0;
    while(s<e)
    {
        A[s] = sortedSubarray[k];
        k += 1;
        s += 1;
    }

}

void mergeSort(Pt* intArray, int intCount)
{
    splitPtArray(0, intCount, intArray);
}

// Quick Hull calculations
Pt newPoint(double x, double y)
{
    Pt pt;

    pt.x = x;
    pt.y = y;

    return pt;
}

void printPointQuickHull(Pt pt)
{
    printf("X: %lf | ", pt.x);
    printf("Y: %lf\n", pt.y);

}

void printPointArrayQuickHull(Pt* ptArray, int len)
{
    for(int i=0; i<len; i++)
    {
        // printf("\n%d\n", i+1); // need
        printPointQuickHull(ptArray[i]);
    }
}

int pointEquals(Pt p1, Pt p2)
{
    return (p1.x == p2.x) && (p1.y == p2.y);
}

Pt* copyPointArray(Pt* ptArray, int len)
{
    Pt* copyPtArray = malloc(sizeof(Pt)*len);

    for(int i=0; i<len; i++)
    {
        copyPtArray[i] = newPoint(ptArray[i].x, ptArray[i].y);
    }
    return copyPtArray;
}

void removeIndexFromPointArray(Pt* ptArray, int* length, int index)
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

double distanceLineToPoint(Pt lpt1, Pt lpt2, Pt dPt)
{
    double result = 0.0;

    double a = (lpt1.y - lpt2.y);
    double b = (lpt2.x - lpt1.x);
    double c = (lpt1.x * lpt2.y) - (lpt2.x * lpt1.y);

    double a_sq = a * a;
    double b_sq = b * b;
    
    double denom = sqrtf( a_sq + b_sq  );
    double numer = (a * dPt.x) + (b * dPt.y) + c;

    result = (double)numer / denom;

    if(result < 0)
        result = result * -1;

    return result;
}

int isPointInTriangle(Pt trLeft, Pt trRight, Pt trTop, Pt p)
{
    double T = getTriangleArea(trLeft, trRight, trTop);
    double A1 = getTriangleArea(trLeft, trRight, p);
    double A2 = getTriangleArea(trLeft, p, trTop);
    double A3 = getTriangleArea(p, trRight, trTop);

    double S = A1 + A2 + A3;
    // printf("T: %lf | A1: %lf | A2: %lf | A3: %lf | S: %lf", T, A1, A2, A3, S);
    if(S - T < 0.00001)
        return TRUE;
    
    return FALSE;
}

double getTriangleArea(Pt p1, Pt p2, Pt p3)
{
    double result = ( p1.x * (p2.y - p3.y) ) - ( p2.x * (p1.y - p3.y) ) + ( p3.x * (p1.y - p2.y) );
    if(result < 0)
        result = result * -1;
    return 0.5 * result;
}

int getMaxDistancePointFromLine(Pt leftMost, Pt rightMost, Pt* pointArray, int length)
{
    int farthestIndex = -1;
    double maxDist = -1;    
    for(int i=0; i<length; i++)
    {
        double currDist = distanceLineToPoint(leftMost, rightMost, pointArray[i]);
        if(currDist > maxDist)
        {
            maxDist = currDist;
            farthestIndex = i;
        }
    }

    return farthestIndex;
}

int determineOrientation(Pt lp1, Pt lp2, Pt p)
{
    // (y-y1) = [(y1-y2)/(x1-x2)](x-x1)

    double orient = ((p.y - lp1.y)*(lp1.x - lp2.x))-((lp1.y-lp2.y)*(p.x-lp1.x));

    if (orient < 0)
        return BOTTOM;
    
    if(orient > 0)
        return TOP;
    
    
    return IGNORE;
}

double lineLengthSq(Pt p1, Pt p2)
{
    double a = p1.x - p2.x;
    double b = p1.y - p2.y;

    return (a*a) + (b*b);
}

double xDist(Pt p1, Pt p2)
{
    double xd = p1.x - p2.x;

    if (xd < 0)
        xd = xd * -1;

    return xd;
}

// returns 0 if in between
int inBetweenX(Pt p1, Pt p2, Pt p)
{
    double maxX, minX;

    if(p1.x > p2.x)
    {
        maxX = p1.x;
        minX = p2.x;
    }
    else
    {
        minX = p1.x;
        maxX = p2.x;
    }

    if(p.x >= minX && p.x <= maxX)
    {
        return 0;
    }

    if(p.x < minX)
    {
        return -1;
    }

    return 1;
}


// quick hull
void recurseTriangleBuild(Pt* pointArray, int* length, Pt leftMost, Pt rightMost, Pt* convexHullArray, int* hullLength)
{   
    // Base Case
    if((*length) == 0)
    {
        // printf("Returning From Recursion since no points exist\n"); // need
        return;
    }


    // printf("Recursive Entry Src size %d", (*length)); // need
    // printPointArrayQuickHull(pointArray, (*length)); // need
    // printf("LEFTMOST POINT\n"); // need
    // printPointQuickHull(leftMost); // need
    // printf("RIGHTMOST POINT\n"); // need
    // printPointQuickHull(rightMost); // need

    // Determine Farthest Point to Include as HULL POINT
    int hullIndex = (*hullLength);

    int farthestFirstHalfIndex = getMaxDistancePointFromLine(leftMost, rightMost, pointArray, (*length));
    Pt farthestPoint = pointArray[farthestFirstHalfIndex];
    convexHullArray[hullIndex++] = newPoint(farthestPoint.x, farthestPoint.y);
    removeIndexFromPointArray(pointArray, length, farthestFirstHalfIndex);
    (*hullLength) = hullIndex;
    // printf("FARTHEST POINT >> Entering Hull...\n"); // need
    // printPointQuickHull(farthestPoint); // need

    // Split Points based on orientation
    int topLength = (*length);
    Pt* topPoints = malloc(sizeof(Pt)*topLength);
    int t = 0;

    int bottomLength = (*length);
    Pt* bottomPoints = malloc(sizeof(Pt)*bottomLength);
    int b = 0;

    for(int i=0; i<(*length); i++)
    {   
        // int topOrient = determineOrientation(leftMost, farthestPoint, pointArray[i]);
        // int bottomOrient = determineOrientation(farthestPoint, rightMost, pointArray[i]);
        // printf("ORIENT TOP %d | ORIENT BOTTOM %d\n", topOrient, bottomOrient);

        int trPt = isPointInTriangle(rightMost, leftMost, farthestPoint, pointArray[i]);
        // printf("IN TRIANGLE %d\n", trPt); // need
        if(!trPt)
        {
            double distLF = distanceLineToPoint(leftMost, farthestPoint, pointArray[i]);
            double distFR = distanceLineToPoint(farthestPoint, rightMost, pointArray[i]);
            // int topOrient = determineOrientation(leftMost, farthestPoint, pointArray[i]);
            // int bottomOrient = determineOrientation(farthestPoint, rightMost, pointArray[i]);
            // printf("LFD: %lf | FRD: %lf >>", distLF, distFR); // need
            
            if(distLF > 0 && distFR > 0)
            {
                // if( distLF < distFR)
                if(inBetweenX(leftMost, farthestPoint, pointArray[i]) == 0)
                {
                    // printf("TOP ORIENT: %d | ", topOrient);
                    // printf("INSERTING TOP...\n"); // need
                    // printPointQuickHull(pointArray[i]); // need
                    topPoints[t++] = newPoint(pointArray[i].x, pointArray[i].y);
                    bottomLength--;
                }
                else // if(bottomOrient == BOTTOM)
                {
                    // printf("BOTTOM ORIENT: %d | ", bottomOrient);
                    // printf("INSERTING BOTTOM...\n"); // need
                    // printPointQuickHull(pointArray[i]); // need
                    bottomPoints[b++] = newPoint(pointArray[i].x, pointArray[i].y);
                    topLength--;
                }
            }
        }
        else
        {
            // printf("Skipping point....\n"); // need
            // printPointQuickHull(pointArray[i]); // need
            topLength--;
            bottomLength--;
        }
        
    }

    // printf("First Subset of size %d\n", topLength); // need
    // printPointArrayQuickHull(topPoints, topLength); // need

    // printf("Second Subset of size %d\n", bottomLength); // need
    // printPointArrayQuickHull(bottomPoints, bottomLength); // need


    // printf("Before Recursion Hull of Size %d\n", (*hullLength)); // need
    // printPointArrayQuickHull(convexHullArray, (*hullLength)); // need


    recurseTriangleBuild(topPoints, &topLength, leftMost, farthestPoint, convexHullArray, hullLength);
    recurseTriangleBuild(bottomPoints, &bottomLength, farthestPoint, rightMost, convexHullArray, hullLength);
    
    // printf("After Recursion Hull of Size %d\n", (*hullLength)); // need
    // printPointArrayQuickHull(convexHullArray, (*hullLength)); // need

}




Pt* computeQuickHullPts(Pt* pointArr, int length, int* hullLength)
{
    Pt* copyPtArr = copyPointArray(pointArr, length); // making a copy to preserve ordering of original set of points
    Pt* convexHullPtArr = malloc(sizeof(Pt)*length);

    // sort points based on increasing x and y
    // bubbleSort(copyPtArr, length);
    mergeSort(copyPtArr, length);

    // printf("After sorting source copy of size %d\n", length); // need
    // printPointArrayQuickHull(copyPtArr, length); // need

    Pt leftMost = copyPtArr[0];
    Pt rightMost = copyPtArr[length-1];
    
    int hullIndex = 0;

    convexHullPtArr[hullIndex++] = newPoint(leftMost.x, leftMost.y);
    int leftIndex = 0;
    removeIndexFromPointArray(copyPtArr, &length, leftIndex);
    // printf("Deleted Index %d, src current size %d\n", leftIndex, length); // need
    // printPointArrayQuickHull(copyPtArr, length); // need

    convexHullPtArr[hullIndex++] = newPoint(rightMost.x, rightMost.y);
    int rightIndex = length-1;
    removeIndexFromPointArray(copyPtArr, &length, rightIndex);
    // printf("Deleted Index %d, src current size %d\n", rightIndex, length); // need
    // printPointArrayQuickHull(copyPtArr, length); // need

    (*hullLength) = hullIndex;
    // printf("Printing Hull of Size %d\n", (*hullLength)); // need
    // printPointArrayQuickHull(convexHullPtArr, (*hullLength)); // need

    // find two sets of points BASED ON THE TWO SIDES OF leftMost and rightMost POINTS
    int topLength = length;
    Pt* topPoints = malloc(sizeof(Pt)*topLength);
    int t = 0;

    int bottomLength = length;
    Pt* bottomPoints = malloc(sizeof(Pt)*bottomLength);
    int b = 0;
    for(int i=0; i<length; i++)
    {   
        int orient = determineOrientation(leftMost, rightMost, copyPtArr[i]);
        // printf("INIT ORIENT: %d | ", orient); // need
        if( orient == BOTTOM)
        {
            // printf("INSERTING TOP...\n"); // need
            // printPointQuickHull(copyPtArr[i]); // need
            topPoints[t++] = newPoint(copyPtArr[i].x, copyPtArr[i].y);
            bottomLength--;
        }
        else if(orient == TOP)
        {
            // printf("INSERTING BOTTOM...\n"); // need
            // printPointQuickHull(copyPtArr[i]); // need
            bottomPoints[b++] = newPoint(copyPtArr[i].x, copyPtArr[i].y);
            topLength--;
        }
        else
        {
            // printf("Skipping point....\n"); // need
            // printPointQuickHull(copyPtArr[i]); // need
            topLength--;
            bottomLength--;
        }
        
    }

    // printf("Init First Subset of size %d", topLength); // need
    // printPointArrayQuickHull(topPoints, topLength); // need

    // printf("Init Second Subset of size %d\n", bottomLength); // need
    // printPointArrayQuickHull(bottomPoints, bottomLength); // need

    recurseTriangleBuild(topPoints, &topLength, leftMost, rightMost, convexHullPtArr, hullLength);
    recurseTriangleBuild(bottomPoints, &bottomLength, leftMost, rightMost, convexHullPtArr, hullLength);


    free(copyPtArr);
    return convexHullPtArr;
}
