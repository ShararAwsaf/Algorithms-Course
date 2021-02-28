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