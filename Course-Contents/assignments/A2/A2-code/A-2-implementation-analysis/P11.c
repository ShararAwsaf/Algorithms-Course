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
        printf("%d ", integers[i]);
    }
    printf("\n");
}

// Main
void p11(char** lines, int lineCount, int intPerLine)
{
    // process inputs
    int integers[MAX_INPUT_SIZE];
    int intCount = -1;
    createIntArrayFromStrings(integers, &intCount, lines, lineCount, intPerLine, " ");
    // printIntArray(integers, intCount);
    
    struct timeb startTime;
    struct timeb endTime;
    
    ftime(&startTime);

    // determine inversions
    countInversions(integers, intCount);
    ftime(&endTime);
    int runTime = (int) (1000.0 * (endTime.time - startTime.time) + (endTime.millitm - startTime.millitm)); 
    printf("Running Time (ms): %d\n", runTime);
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

    printf("Inversions = %d\n", count);
    return count;
}

