/**
 * Name: Sharar Mahmood
 * Id: 0955835
 * Date: 6 Feb 2021
 * Assignment: A2
 * **/

# include "P12.h"

void p12(char** lines, int lineCount, int intPerLine)
{
    // process inputs
    int integers[MAX_INPUT_SIZE];
    int intCount = -1;
    createIntArrayFromStrings(integers, &intCount, lines, lineCount, intPerLine, " ");
    // printIntArray(integers, intCount);
    
    struct timeb startTime;
    struct timeb endTime;
    
    ftime(&startTime);
    // determine inversions using Divide and Conquer
    countInversionsDC(integers, intCount);
    ftime(&endTime);
    int runTime = (int) (1000.0 * (endTime.time - startTime.time) + (endTime.millitm - startTime.millitm)); 
    printf("Running Time (ms): %d\n", runTime);
}

void splitArray(int s, int e, int* count, int* A)
{
    if (s == e-1)
    {
        return;
    }

    int m = (s+e) / 2;
    
    splitArray(s,m, count, A);
    splitArray(m,e, count, A);

    mergeArrays(s, m, e, count, A);

}

void mergeArrays(int s, int m, int e, int* count, int* A)
{
    
    int l = s;
    int r = m;
    int k = 0;
    int sortedSubarray[MAX_INPUT_SIZE];

    int smallerNumber = 0;

    while (l<m && r<e)
    {
        if (A[l] > A[r])
        {
            smallerNumber = A[r];
            // since current Left item  > current Right item
            // so all items to right of current Left is greater than current right item
            (*count) = (*count) + m - l;
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

int countInversionsDC(int* intArray, int intCount)
{
    int count = 0;
    splitArray(0, intCount, &count, intArray);
    printf("Inversions = %d\n", count);
    return count;
}