#include "stdio.h"
#include  "stdlib.h"
#include "string.h" // remove this when you are done

#define TRUE 1
#define FALSE 0

#define TEXTLENGTH 100
#define PATTERNLENGTH 5
#define MAXTABLESIZE 28 // there will 1-27 indices

#define alphabetCount(c) ((int)c) - 65 + 1
#define toAlphabet(i) (char)(i + 64)
#define toUpper(c) ((int)c) >= 97 ? ((int)c) - 32 : ((int)c)
#define max(a, b) ((int)b) > ((int)a) ? (int)b : (int)a
#define min(a, b) ((int)b) < ((int)a) ? (int)b : (int)a

void printTable(char* keys, int keyCount, int* valueTable);
void toUpperStr(char* charArray, int len);
void copySrcToDest(char* src, char* dest, int len);
void printStringArray(char** sArray, int len);

char** getAllSuffixes(char* str, int len);
char** getAllPrefixes(char* str, int len);
int searchForStringInArray(char* searchTerm, char** searchSpace, int spaceLen);
int matchStrings(char* s1, int Ls1, char* s2, int Ls2);