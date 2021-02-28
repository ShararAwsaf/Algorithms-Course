# ifndef IMPLEMENTATION_H
# include "implementation.h"
# endif

void getText(char* datapath, char** T, int* TL)
{
    FILE* fptr = fopen(datapath, "r");
    int i = 0;
    int j = 0;
    int prev = -1;
    char c;

    while(fread(&c, 1, 1, fptr))
    {
        // printf("%c",c);
        // printText(T, i+1);
        if(c == '\n')
        {
            // skips new lines
        }
        else if(c == ' ')
        {
            T[i][j]='\0'; // end previous word
            i += 1;
            j = 0;   
        }
        else
        {
            if(i > prev)
            {
                T[i] = malloc(sizeof(char)*MAX_SIZE); // create a new line
                prev = i;
            }

            T[i][j] = c;
            j += 1;
        }
    }
    *TL = i;
    fclose(fptr);
}

void getPattern(char* p)
{
    scanf("%s", p);
}

void printText(char** T, int TL)
{
    for(int i=0; i< TL; i++)
    {
        printf("%d. %s\n", i+1, T[i]);
    }
}