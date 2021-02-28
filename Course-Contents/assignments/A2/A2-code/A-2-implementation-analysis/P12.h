/**
 * Name: Sharar Mahmood
 * Id: 0955835
 * Date: 6 Feb 2021
 * Assignment: A2
 * **/

# include "P11.h"

// driver of divide and conquer inversion counts
void p12(char** lines, int lineCount, int intPerLine);

// subroutine divides the array of ints into sub arrays of equal or almost equal size
void splitArray(int s, int e, int* count, int* A);

// subroutine merging two sorted array of ints into a super array that is also sorted
void mergeArrays(int s, int m, int e, int* count, int* A);

// calculates inversions using divide and conquer strategy
int countInversionsDC(int* intArray, int intCount);