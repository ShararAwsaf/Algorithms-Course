/**
 * Name: Sharar Mahmood
 * Id: 0955835
 * Date: 6 Feb 2021
 * Assignment: A2
 * **/

# include "P21.h"

void p21(char** lines, int lineCount)
{
    Point points[MAX_POINT_COUNT];
    int pointCount = -1;

    createPointArrayFromStrings(points, &pointCount, lines, lineCount, " ");
    // printPointArray(points, pointCount);
    // printf("SORTED\n");

    // Sort points to ensure starting from extreme point
    
    // printPointArray(points, pointCount);

    Point hull[MAX_POINT_COUNT];
    int hullSize = 0;

    struct timeb startTime;
    struct timeb endTime;
    
    ftime(&startTime);
    convexHullBruteForce(points, pointCount, hull, &hullSize);
    ftime(&endTime);
    int runTime = (int) (1000.0 * (endTime.time - startTime.time) + (endTime.millitm - startTime.millitm)); 

    sortPoints(hull, hullSize);
    printPointArray(hull, hullSize);
    printf("CONVEX HULL SIZE: %d\n", hullSize);
    printf("Running Time (ms): %d\n", runTime);
}

void convexHullBruteForce(Point* points, int pointCount, Point* hull, int* hullSize)
{   
    // Original working solution
    // hull[0] = points[0];
    // int hullSize = 1;

    Point rejected[MAX_POINT_COUNT];
    int rejectedSize = 0;

    Point leftExtremePoint = points[0];
    int leftExtremeIndex = 0;
    for(int i=0; i< pointCount; i++)
    {
        if( (points[i].x < leftExtremePoint.x) ||  (points[i].x == leftExtremePoint.x && points[i].y < leftExtremePoint.y) )
        {
            leftExtremePoint = points[i];
            leftExtremeIndex = i;
        }
    }

    // make left extreme the start point (to avoid starting and inserting internal point)
    Point tmpPoint = points[0];
    points[0] = leftExtremePoint;
    points[leftExtremeIndex] = tmpPoint;

    for(int i=0; i<pointCount-1; i++)
    {
        for(int j=i+1; j<pointCount; j++)
        {
            int prevSign = 0;
            Point farthestPoint = points[j];
            int k = 0;

            Point p1 = points[i];
            Point p2 = points[j];

            double a = p2.y - p1.y;
            double b = p1.x - p2.x;
            double c = (p1.x * p2.y) - (p2.x * p1.y);

            Point tempRejected[MAX_POINT_COUNT];
            int tempRejectedSize = 0;

            for(k=0; k<pointCount; k++)
            {
                // skip the current points under consideration
                // if(k==pointCount-1-i || k == pointCount-1-j)
                if(k == i || k == j)
                // if( (copyPoints[k].x == points[i].x && copyPoints[k].y == points[i].y) || (copyPoints[k].x == points[j].x && copyPoints[k].y == points[j].y))
                {
                    continue;
                }

                int currSign = signOfPointWithRespectToLineCoeffs(a, b, c, points[k]);

                // Collinear case choose the farthest between the two
                if ( currSign == 0 )
                {
                    // printf("COLLINEAR DETECTED\n");
                    // printPoint(points[i]);
                    // printPoint(farthestPoint);
                    // printPoint(points[k]);

                    // /**
                    //  * Skipping the collinear detection *
                    double d_i_k = distSquare(points[i], points[k]);
                    double d_i_f = distSquare(points[i], farthestPoint);
                    // printf("I:K=%lf | I:F=%lf\n", d_i_k, d_i_f);
                    if ( d_i_k > d_i_f )
                    {
                        // track collinear instances
                        tempRejected[tempRejectedSize++] = farthestPoint;
                        farthestPoint = points[k];

                    }
                    // **/
                    
                    // printf("FARTHEST : ");
                    // printPoint(farthestPoint);
                    continue;
                }

                if (prevSign == 0)
                {
                    prevSign = currSign;
                    continue;
                }

                // points don't lie on same side of line
                if(prevSign != currSign)
                    break;
            }

            if(k == pointCount)
            {
                // reject collinear instances : to avoid repetition
                for(int t = 0; t < tempRejectedSize; t++)
                {
                    rejected[rejectedSize++] = tempRejected[t];
                }

                // avoid double insert
                if( exhaustiveSearchPoints(rejected, rejectedSize, points[i]) == FALSE )
                {
                    hull[(*hullSize)] = points[i];
                    (*hullSize) += 1;
                    rejected[rejectedSize++] = points[i];

                }

                // avoid double insert
                if( exhaustiveSearchPoints(rejected, rejectedSize, farthestPoint) == FALSE )
                {
                    hull[(*hullSize)] = farthestPoint;
                    (*hullSize) += 1;
                    rejected[rejectedSize++] = farthestPoint;

                }
                

                // Previous correct implementation
                // hull[hullSize] = farthestPoint;
                // hullSize += 1;
            }
        }
        // printf("i : %d\n",i);
    }

}


void printPoint(Point pt)
{
    printf("X: %f | Y: %f\n", pt.x, pt.y);
}

void createPointArrayFromStrings(Point* pointArray, int* pointCount, char** strings, int stringCount, char* separator)
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
            // printf("%s\n",token);
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

void printPointArray(Point* points, int pointCount)
{
    for(int i=0; i< pointCount; i++)
    {
        printPoint(points[i]);
    }
}

void sortPoints(Point* points, int pointCount)
{
    for(int i=0; i<pointCount-1; i++)
    {
        for(int j=i+1; j<pointCount; j++)
        {
            Point tmp;
            if(points[i].x > points[j].x || ( points[i].x == points[j].x && points[i].y > points[j].y ) )
            {
                tmp = points[i];
                points[i] = points[j];
                points[j] = tmp; 
            }

        }
    }
}

int exhaustiveSearchPoints(Point* points, int pointCount, Point searchPoint)
{
    for(int i=0; i<pointCount; i++)
    {
        double xDiff = points[i].x - searchPoint.x;
        if(xDiff < 0)
            xDiff *= -1;
        
        double yDiff = points[i].y - searchPoint.y;
        if(yDiff < 0)
            yDiff *= -1;
        

        if( xDiff < 0.00001 &&  yDiff < 0.00001)
            return TRUE;
    }
    return FALSE;
}

void insertUniquePoint(Point* points, int* pointCount, Point insertPoint)
{
    int searchResult = exhaustiveSearchPoints(points, *pointCount, insertPoint);

    if (searchResult == FALSE)
    {
        points[*pointCount] = insertPoint;
        (*pointCount) = (*pointCount)+1;
    }
}

// Math helpers
int signOfPointWithRespectToLine(Point p1, Point p2, Point inputPt)
{
    double a = p2.y - p1.y;
    double b = p1.x - p2.x;
    double c = (p1.x * p2.y) - (p2.x * p1.y);

    double result = (a*inputPt.x) + (b*inputPt.y) - c;

    if(result == 0.0)
    {
        return 0;
    }
    else if(result > 0.0)
    {
        return 1;
    }
    return -1;
}

int signOfPointWithRespectToLineCoeffs(double a, double b, double c, Point inputPt)
{
    
    double result = (a*inputPt.x) + (b*inputPt.y) - c;

    if(result == 0)
    {
        return 0;
    }
    else if(result > 0)
    {
        return 1;
    }
    return -1;
}

double distSquare(Point p1, Point p2)
{
    double a = p1.x - p2.x;
    double b = p1.y - p2.y;

    return (a*a) + (b*b);
}



