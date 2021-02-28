/**
 * Name: Sharar Mahmood
 * Id: 0955835
 * Date: 6 Feb 2021
 * Assignment: A2
 * **/

# include "P11.h"

// Helpers
void createIntArrayFromStrings(int* intArray, int* intCount, char** strings, int stringCount, int intPerLine, char* separator)
{
    *intCount = stringCount*intPerLine;
    int index = 0;

    for(int i=0; i<stringCount; i++)
    {
        char* token = strtok(strings[i], separator);
        while(token != NULL)
        {
            intArray[index] = atoi(token);
            // printf("%d\n", intArray[index]);
            index += 1;

            token = strtok(NULL, separator);
        }
    }
}

void printIntArray(int* integers, int intCount)
{
    printf("TOTAL INTS: %d\n", intCount);
    for(int i=0; i< intCount; i++)
    {
        printf("%d\n", integers[i]);
    }
}

// Main
void p11(char** lines, int lineCount)
{
    // process inputs
    int integers[MAX_INPUT_SIZE];
    int intCount = -1;
    createIntArrayFromStrings(integers, &intCount, lines, lineCount, 5, " ");
    // printIntArray(integers, intCount);
    
    // determine inversions
    int inversions = countInversions(integers, intCount);
    printf("Inversions = %d\n", inversions);
}

int countInversions(int* intArray, int intCount)
{
    int count = 0;

    for(int i = 0; i<intCount-1; i++)
    {
        for(int j = i+1; j<intCount; j++)
        {
            if(intArray[i] > intArray[j])
            {
                count += 1;
                // printf("%d. %d > %d\n", count, intArray[i], intArray[j]);
            }
        }
    }

    return count;
}

