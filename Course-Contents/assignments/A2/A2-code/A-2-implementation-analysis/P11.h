/**
 * Name: Sharar Mahmood
 * Id: 0955835
 * Date: 6 Feb 2021
 * Assignment: A2
 * **/

# include "utils.h"
# include <sys/timeb.h>

# define MAX_INPUT_SIZE 50000

// creates an array of ints from a list of lines containing strings of numbers
void createIntArrayFromStrings(int* intArray, int* intCount, char** strings, int stringCount, int intPerLine, char* separator);

// prints array of ints
void printIntArray(int* integers, int intCount);

// driver code for brute force inversion count
void p11(char** lines, int lineCount, int intPerLine);

// calculate brute force inversion count
int countInversions(int* intArray, int intCount);