# include "P21.h"

void p21(char** lines, int lineCount)
{
    Point points[MAX_POINT_COUNT];
    int pointCount = -1;

    createPointArrayFromStrings(points, &pointCount, lines, lineCount, " ");
    // printPointArray(points, pointCount);
    // printf("SORTED\n");
    sortPoints(points, pointCount);
    // printPointArray(points, pointCount);
    convexHullBruteForce(points, pointCount);

}

// assumes points are sorted by x and tie broken using ascending y
void convexHullBruteForce(Point* points, int pointCount)
{
    Point hull[MAX_POINT_COUNT];
    hull[0] = points[0];
    int hullSize = 1;

    for(int i=0; i<pointCount-1; i++)
    {
        for(int j=i+1; j<pointCount; j++)
        {
            int prevSign = 0;
            Point farthestPoint = points[j];
            int k = 0;
            for(k=0; k<pointCount; k++)
            {
                // skip the current points under consideration
                if(k == i || k == j)
                {
                    continue;
                }

                int currSign = signOfPointWithRespectToLine(points[i], points[j], points[k]);

                // Collinear case choose the farthest between the two
                if (currSign == 0)
                {
                    // printf("COLLINEAR DETECTED\n");
                    // printPoint(points[i]);
                    // printPoint(farthestPoint);
                    // printPoint(points[k]);

                    double d_i_k = distSquare(points[i], points[k]);
                    double d_i_f = distSquare(points[i], farthestPoint);
                    // printf("I:K=%lf | I:F=%lf\n", d_i_k, d_i_f);

                    if ( d_i_k > d_i_f )
                    {
                        farthestPoint = points[k];
                    }
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
                // insertUniquePoint(hull, &hullSize, points[i]);
                insertUniquePoint(hull, &hullSize, farthestPoint);
            }

        }
        printf("i=%d\n",i);
    }

    sortPoints(hull, hullSize);
    printPointArray(hull, hullSize);
    printf("CONVEX HULL SIZE: %d\n", hullSize);

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

            if (coordinate > 0.0)
            {
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
            }

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
        if(points[i].x == searchPoint.x && points[i].y == searchPoint.y)
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

double distSquare(Point p1, Point p2)
{
    double a = p1.x - p2.x;
    double b = p1.y - p2.y;

    return (a*a) + (b*b);
}



