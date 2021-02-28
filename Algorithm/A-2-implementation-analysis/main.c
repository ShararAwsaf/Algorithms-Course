/**
 * Name: Sharar Mahmood
 * Id: 0955835
 * Date: 6 Feb 2021
 * Assignment: A2
 * **/

# include "utils.h"
# include "P11.h"
# include "P21.h"


int main(int argc, char** argv)
{
    if(argc != 3)
    {
        printf("Please provide program name and filename\n");
        return -1;
    }

    for(int i=0; i<argc; i++)
    {
        printf("%d. %s\n", i+1, argv[i]);
    }

    int LC = -1;
    char* lines[MAX_LINE_COUNT];
    readFile(argv[2], lines, &LC);
    // printLines(lines, LC);

    if(  strcmp(argv[1], "p11") == 0 || strcmp(argv[1], "P11") == 0)
    {
        printf("Executing program 1-1\n");
        p11(lines, LC);
    }
    else if(  strcmp(argv[1], "p21") == 0 || strcmp(argv[1], "P21") == 0)
    {
        printf("Executing program 2-1\n");
        p21(lines, LC);
    }
    else
    {
        printf("%s is an invalid program name\n", argv[1]);
    }
}