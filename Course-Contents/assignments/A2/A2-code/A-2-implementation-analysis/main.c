/**
 * Name: Sharar Mahmood
 * Id: 0955835
 * Date: 6 Feb 2021
 * Assignment: A2
 * **/

# include "utils.h"
# include "P11.h"
# include "P12.h"
# include "P21.h"
# include "P22.h"




int main(int argc, char** argv)
{
    if(argc != 3)
    {
        printf("Please provide program name and filename\n");
        return -1;
    }

    printf("Program Inputs:\n");
    for(int i=1; i<argc; i++)
    {
        printf("%d. %s\n", i, argv[i]);
    }

    int LC = -1;
    char* lines[MAX_LINE_COUNT];
    readFile(argv[2], lines, &LC);
    // printLines(lines, LC);
    
    int intPerLine = 5;
    if(  strcmp(argv[1], "p11") == 0 || strcmp(argv[1], "P11") == 0)
    {
        printf("Executing program 1-1: Brute Force Inversion Count\n");
        printf("Integers per line in file: ");
        scanf("%d", &intPerLine);
        p11(lines, LC, intPerLine);
    }
    else if(  strcmp(argv[1], "p12") == 0 || strcmp(argv[1], "P12") == 0)
    {
        printf("Executing program 1-2: Divide & Conquer Inversion Count\n");
        printf("Integers per line in file: ");
        scanf("%d", &intPerLine);
        p12(lines, LC, intPerLine);
    }
    else if(  strcmp(argv[1], "p21") == 0 || strcmp(argv[1], "P21") == 0)
    {
        printf("Executing program 2-1: Brute Force Convex Hull\n");
        p21(lines, LC);
    }
    else if(  strcmp(argv[1], "p22") == 0 || strcmp(argv[1], "P22") == 0)
    {
        printf("Executing program 2-1: Quick Hull\n");
        p22(lines, LC);
    }
    else
    {
        printf("%s is an invalid program name\n", argv[1]);
    }
}