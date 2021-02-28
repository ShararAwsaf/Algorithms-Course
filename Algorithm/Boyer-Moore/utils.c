#include "utils.h"

void printTable(char* keys, int keyCount, int* valueTable)
{
    if(keyCount)
    {
        for(int i=0; i<keyCount; i++)
        {
            char k = keys[i];
            printf("KEY: %c | VALUE: %d\n", k, valueTable[alphabetCount(k)]);
        }
    }
    else
    {
        for(int i=1; i<MAXTABLESIZE-1; i++)
        {
            char c = toAlphabet(i);
            printf("KEY: %c | VALUE: %d\n", c, valueTable[i]);
        }
    }
}

void toUpperStr(char* charArray, int len)
{
    for(int i=0; i<len; i++)
    {
        char c = charArray[i];
        charArray[i] = (char)toUpper(c);
    }
}

void copySrcToDest(char* src, char* dest, int len)
{
    for(int i=0; i<len; i++)
    {
        dest[i] = src[i];
    }
    dest[len]='\0';
}

void printStringArray(char** sArray, int len)
{
    for(int i=0; i<len; i++)
    {
        printf("%d. %s\n", i+1, sArray[i]);
    }
}

char** getAllSuffixes(char* str, int len)
{
    if(len <= 0)
        return NULL;

    char** suffixArray = malloc(sizeof(char*)*len);
    for(int i=len-1; i>=0; i--)
    {   
        int currIndex= len-1-i;
        suffixArray[currIndex] = malloc(sizeof(char)*len);
        int k = 0;
        char* currSuffix = suffixArray[currIndex];
        for(int j=i; j<len; j++)
        {
            currSuffix[k++] = str[j];
        }
        currSuffix[k++] = '\0';
    }

    return suffixArray;
}


char** getAllPrefixes(char* str, int len)
{
    if (len == 0)
        return NULL;
    
    char** prefixArray = malloc(sizeof(char**)*len);

    for(int i=0; i<len; i++)
    {
        prefixArray[i] = malloc(sizeof(char*)*len);
        char* currPrefix = prefixArray[i];
        int k = 0;
        for(int j=0; j<=i; j++)
        {
            currPrefix[k++] = str[j];
        }
        currPrefix[k] = '\0';

    }
    
    return prefixArray;

}


// Raw string comparison
int matchStrings(char* s1, int Ls1, char* s2, int Ls2)
{
    if(Ls1 != Ls2)
        return FALSE;

    for(int i=0; i<Ls1; i++)
    {
        if(s1[i] != s2[i])
            return FALSE;
    }
    return TRUE;
}

int searchForStringInArray(char* searchTerm, char** searchSpace, int spaceLen)
{
    for(int i=0; i<spaceLen; i++)
    {
        if(strcmp(searchTerm, searchSpace[i]) == 0)
            return i;
    }
    return -1;
}