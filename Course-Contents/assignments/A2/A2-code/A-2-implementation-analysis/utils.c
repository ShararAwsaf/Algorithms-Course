/**
 * Name: Sharar Mahmood
 * Id: 0955835
 * Date: 6 Feb 2021
 * Assignment: A2
 * **/

#include "utils.h"

void readFile(char* filePath, char** lines, int* totalLines)
{
    FILE* filePtr = NULL;

    filePtr = fopen(filePath, "r");

    if (filePtr == NULL)
    {
        printf("%s does not exist...\n", filePath);
        return;
    }

    
    int i = 0;
    int j = 0;
    char c;
    int prev = -1;
    // read character by character
    while(fread(&c, 1, 1, filePtr))
    {
        if(c == '\n')
        {
            lines[i][j]='\0'; // end previous line
            i += 1;
            j = 0;   
        }
        else
        {
            if(i > prev)
            {
                lines[i] = malloc(sizeof(char)*MAX_LINE_SIZE); // create a new line
                prev = i;
            }

            lines[i][j] = c;
            j += 1;
        }
        
    }
    *totalLines = i+1;

    fclose(filePtr);
}

void printLines(char** lines, int lineCount)
{
    if(lineCount <= 0)
    {
        printf("No lines to print\n");
        return;
    }

    printf("LINE COUNT: %d\n", lineCount);
    for(int i=0; i<lineCount; i++)
    {
        printf("%s\n",lines[i]);
    }

}

