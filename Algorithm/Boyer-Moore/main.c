#include "utils.h"

// headers
int boyerMooreSearch(char* T, int TL, char* P, int PL);
int compareTextToTables(char* T, int TL, char* P, int PL, int* badCharTable, int* goodSuffLTable, int* goodSuffHTable);
int getGoodSuffixSkip(char* t, int tL, int* gsTable);
int horspoolSearch(char* T, int TL, char* P, int PL);
int* buildBadCharacterTable(char* P, int PL);
int* getGoodSuffLTable(char* P, int PL);
int* getGoodSuffHTable(char* P, int PL);


// test headers
void testBoyerMoore(char* text, int textLength, char* pattern, int patternLength);
void testHorspool(char* text, int textLength, char* pattern, int patternLength);

void testToUpper(char* t, int l);
void testGetSuffixArray();
void testGetPrefixArray();

void testGoodSuffixSkipL(char* P, int PL); 
void testGoodSuffixSkipH(char* P, int PL);


int main(int argc, char* argv[])
{
    if(argc != 5)
    {
        printf("Please supply 4 args in the order TEXT, TEXT LENGTH, PATTERN, PATTERN LENGTH\n");
        return -1;
    }

    char* text = argv[1];
    int textLength = atoi(argv[2]);

    char* pattern = argv[3];
    int patternLength = atoi(argv[4]);

    // testHorspool(text, textLength, pattern, patternLength);

    // testBoyerMoore(text, textLength, pattern, patternLength);
    // testToUpper(text, textLength);
    // testToUpper(pattern, patternLength);

    // testGetSuffixArray();
    // testGetPrefixArray();


    testGoodSuffixSkipL(pattern, patternLength);
    // testGoodSuffixSkipH(pattern, patternLength);

    return 0;
}


int boyerMooreSearch(char* T, int TL, char* P, int PL)
{
    // INITIIALIZATION
    // copy source to avoid overwrite and upper case
    char CT[TL+1];
    char CP[PL+1];
    copySrcToDest(T, CT, TL);
    copySrcToDest(P, CP, PL);
    
    toUpperStr(CT, TL);
    toUpperStr(CP, PL);
    printf("SRC TEXT: %s | DEST TEXT: %s\n", T, CT);
    printf("SRC PATTERN: %s | DEST PATTERN: %s\n", P, CP);

    // Pre-process
    // table initialization
    int* badCharTable = buildBadCharacterTable(CP, PL);

    int* goodSuffLTable = NULL;
    int* goodSuffHTable = NULL;
    int index = compareTextToTables(CT, TL, CP, PL, badCharTable, goodSuffLTable, goodSuffHTable);
    

    return index;
}

int compareTextToTables(char* T, int TL, char* P, int PL, int* badCharTable, int* goodSuffLTable, int* goodSuffHTable)
{
    int indexMatched = -1;

    // suffix
    char* t = malloc(sizeof(char)*TL + 1);
    int ti=0;
    t[ti++] = '\0';

    int i = 0;

    for(int j=PL-1; j >= 0 && i<=TL-PL; j--)
    {
        
        // calculate absolute position in text
        int currentTextPos = i+j;
        printf("Comparing\n");
        printf("Pi: %d | P: %c\n", j, P[j]);
        printf("Ti: %d | T: %c\n", currentTextPos, T[currentTextPos]);

        
        // matches from right to left
        if(P[j] != T[currentTextPos])
        {
            // bad character jump
            int badCharSkip = badCharTable[alphabetCount(T[currentTextPos])];

            // good suffix jump
            int goodSuffixSkip = getGoodSuffixSkip(t, ti, goodSuffLTable);// dummy
            
            // max of the two is desired jump
            int boyerMooreSkip = max(badCharSkip, goodSuffixSkip);
            i += boyerMooreSkip;
            printf("Mismatch at %d, Skip Amount %d\n", currentTextPos, boyerMooreSkip);

            indexMatched = -1; // reinitialize matched index
            j = PL; // start comparing from back
        }
        else
        {
            // populate suffix
            t[ti++] = P[j];
            t[ti++] = '\0';
            indexMatched = currentTextPos;
        }   
    }
    
    printf("Ending Comparison\n");
    free(t);
    return indexMatched;
}

int getGoodSuffixSkip(char* t, int tL, int* gsTable)
{
    int skipAmount = 0;
    // int i = 0;
    // while(i<tL && gsTable[t[i]] == 0)
    // {
    //     skipAmount = gsTable[t[i]];
    //     i++;
    // }


    return skipAmount;
}

// Preprocessing for Bad Character Table
int* buildBadCharacterTable(char* P, int PL)
{
    int* badCharTable = malloc(sizeof(int)*MAXTABLESIZE);

    for(int i=0; i < MAXTABLESIZE; i++)
    {
        badCharTable[i] = PL;
    }

    for(int i=0; i<PL; i++)
    {
        int key = alphabetCount(P[i]);
        
        // where does curr character occur from end
        int shiftAmount = max(1, PL - i - 1);
        printf("%c = %d | SHIFT: %d\n", P[i], key, shiftAmount);

        // for last instance, least shift amount takes precedence
        if(i==PL-1)
            badCharTable[key] = min(badCharTable[key], shiftAmount);
        else
            badCharTable[key] = shiftAmount;
    }

    // THIS CAUSES CODE TO NOT WORK FOR: ComputerScience -> Science
    // VERIFY : IN CASE THE LAST CHARACTER DOESN'T MATCH WE CAN SKIP THE WHOLE PATERN
    // badCharTable[alphabetCount(P[PL-1])] = PL;

    // notice : * is no more needed since we have alphabet table
    printTable(P, 0, badCharTable); // view full table using 0
    // printTable(CP, PL, badCharTable);

    return badCharTable;
}


// Horspool Algorithm
int horspoolSearch(char* T, int TL, char* P, int PL)
{

    // INITIIALIZATION
    // copy source to avoid overwrite and upper case
    char CT[TL+1];
    char CP[PL+1];
    copySrcToDest(T, CT, TL);
    copySrcToDest(P, CP, PL);
    
    toUpperStr(CT, TL);
    toUpperStr(CP, PL);
    printf("SRC TEXT: %s | DEST TEXT: %s\n", T, CT);
    printf("SRC PATTERN: %s | DEST PATTERN: %s\n", P, CP);


    int currentIndexPosition = 0;
    
    int* badCharTable = buildBadCharacterTable(CP, PL);
    int found = TRUE;

    while(currentIndexPosition <= TL-PL)
    {   
        found = TRUE;
        printf("CURRENT INDEX: %d\n", currentIndexPosition);
        // one to one search from the back
        for(int j=PL-1; j>=0; j--)
        {
            if(CT[currentIndexPosition+j] != CP[j])
            {
                found = FALSE;
                break;
            }
        }

        if(found)
            return currentIndexPosition;

        currentIndexPosition += badCharTable[alphabetCount(CT[currentIndexPosition+PL-1])];
    }

    if(!found)
        return -1;

    return currentIndexPosition;
}


int* getGoodSuffLTable(char* P, int PL)
{
    

    int* L = malloc(sizeof(int)*PL);


    // char** allSuffixesOfP = getAllSuffixes(P, PL);

    printf("SOURCE: %s\n\n", P);
    for(int i=0; i< PL; i++)
    {

        // Get P[i..N]
        int remIndex = 0;
        char* searchTerm = malloc(sizeof(char)*PL);

        for (int j=i; j<PL; j++)
        {
            searchTerm[remIndex++] = P[j];
        }
        searchTerm[remIndex] = '\0';

        // Get all suffixes of P[1..L[i]]
        // L[i] = k, where k < N and P[i..N] is a suffix of P[1..1+k] (e.g. when i=1 k=N-1)
        char* prefix = malloc(sizeof(char)*PL);
        int k = 0;
        int maxPos = -1;

        while(k < PL) // a maximum of i..n number of characters can be taken for searching for suffix from beginning (suffix of prefix of size n-i)
        {
            prefix[k] = P[k];
            k += 1;
            prefix[k] = '\0';
        

            printf("PREFIX: %s (1..%d)\n", prefix, k);
            printf("SEARCH: %s (%d..%d)\n", searchTerm, i+1, PL);

            char** suffixOfPrefix =  getAllSuffixes(prefix, k);
            printf("TOTAL SUFFIXES (BACK TO FRONT ORDER): %d\n", k);
            printStringArray(suffixOfPrefix, k);
            // int findIndex = searchForStringInArray(searchTerm, suffixOfPrefix, k);
            
            int j = k-1;
            // search in reverse to do traversal from beginning to end
            while(j >= 0)
            {
                int findIndex = matchStrings(suffixOfPrefix[j], j+1, searchTerm, remIndex);

                if(findIndex == TRUE)
                {
                    printf("FOUND %s at %d | i=%d\n", searchTerm, j, i);

                    if(i == 0)
                        maxPos = j;
                    else if(i > 0 && j < PL-1 && suffixOfPrefix[j+1][0] != P[i-1])
                    {
                        printf("Comparing %d (%c) | %d (%c)\n", suffixOfPrefix[j+1][0], P[PL-maxPos-1-1], i-1, P[i-1]);

                        maxPos = max(maxPos, j);
                    }
                }
                j -= 1;
            }

        }
        L[i] = maxPos;

        // Check Character preceding suffix is not equal to P[i-1]
        // if(i > 0 && maxPos > 0)
        // {
        //     printf("Comparing %d (%c) | %d (%c)\n", PL-maxPos-1-1, P[PL-maxPos-1-1], i-1, P[i-1]);

        //     if(P[PL-maxPos-1-1] == P[i-1])
        //         L[i] = 0; 
        // }

        // if(findIndex >= 0 )
        // {
        //     printf("FOUND %s at %d\n", searchTerm, findIndex);
        //     if(findIndex > 0 && i > 0 && prefix[findIndex-1] != P[i-1])
        //     {
        //         printf("****\n");
        //         printf("SUFFIX PREV: %c | SEARCH PREV: %c\n", prefix[findIndex-1], P[i-1]);
        //         printf("****\n");

        //         L[i] = findIndex;
        //     }
        //     else
        //     {
        //         L[i] = 0;
        //     }
            
        // }
        // else
        // {
        //     L[i] = 0;
        // }
        
    }

    return L;
}


// TESTS
void testBoyerMoore(char* text, int textLength, char* pattern, int patternLength)
{

    printf("T : %s | LEN: %d\n", text, textLength);
    printf("P : %s | LEN: %d\n", pattern, patternLength);

    printf("Performing Horspool Search....\n");
    int result = boyerMooreSearch(text, textLength, pattern, patternLength);

    if(result == -1)
    {
        printf("No match found\n");
    }
    else
    {
        printf("Match found at %d of text\n", result);
    }
    
}


void testHorspool(char* text, int textLength, char* pattern, int patternLength)
{
    printf("T : %s | LEN: %d\n", text, textLength);
    printf("P : %s | LEN: %d\n", pattern, patternLength);

    printf("Performing Boyer Moore Search....\n");
    int result = horspoolSearch(text, textLength, pattern, patternLength);

    if(result == -1)
    {
        printf("No match found\n");
    }
    else
    {
        printf("Match found at %d of text\n", result);
    }
}

void testToUpper(char* t, int l)
{
    printf("BEFORE : %s\n", t);
    toUpperStr(t, l);
    printf("AFTER : %s\n", t);
}

void testGetSuffixArray()
{
    char s[100] = "SUPERCALIFRAGILISTICEXPIALIDOCIOUS";
    int l = strlen(s);
    char** suffArr = getAllSuffixes(s, l);
    for(int i=0; i<l; i++)
    {
        printf("%d. %s\n", i+1, suffArr[i]);
    }
}

void testGetPrefixArray()
{
    char s[100] = "SUPERCALIFRAGILISTICEXPIALIDOCIOUS";
    int l = strlen(s);
    char** suffArr = getAllPrefixes(s, l);
    for(int i=0; i<l; i++)
    {
        printf("%d. %s\n", i+1, suffArr[i]);
    }
}


void testGoodSuffixSkipL(char* P, int PL)
{
    // char P[100] = "CABCABCAB";
    // int PL = strlen(P);

    int* L = getGoodSuffLTable(P, PL);    

    printf("\nL TABLE\n");
    for(int i=0; i < PL; i++)
    {
        printf("%d\n", L[i]);
    }
}


void testGoodSuffixSkipH(char* P, int PL)
{
    // char prefix[100] = "";
    // int k = 0;

    char** prefixesP = getAllPrefixes(P, PL); // 1..1, 1..2, 1..n
    char** suffixesP = getAllSuffixes(P, PL); // n..n, n-1..n, i..n
    printf("ALL PREFIXES OF %s\n", P);
    printStringArray(prefixesP, PL);

    printf("ALL SUFFIXES OF %s\n", P);
    printStringArray(suffixesP, PL);

    int* H = malloc(sizeof(int)*PL);

    for(int i=0; i<PL; i++)
    {
        // prefix[k++] = P[i];
        // prefix[k] = '\0';
        
        char* prefix = suffixesP[i];

        int largestSuffixSize = 0;
        int largestSuffixIndex = -1;

        char** suffixOfPrefix = getAllSuffixes(prefix, i+1);

        printf("SUFFIXES OF PREFIX: %s (0..%d)\n", prefix, i);
        printStringArray(suffixOfPrefix, i+1);

        // Check for prefix of P in Suffix of i..n
        for(int j=0; j< i+1; j++)
        {   
            int found = searchForStringInArray(suffixOfPrefix[j], prefixesP, PL);
            if(found >= 0)
            {
                if(strlen(suffixOfPrefix[j]) >= largestSuffixSize)
                {
                    largestSuffixSize = j+1;
                    largestSuffixIndex = j;
                }
                printf("SUFFIX : %s FOUND AT %d (%s)\n", suffixOfPrefix[j], found, prefixesP[found]);
            }
        }

        if(largestSuffixSize)
        {
            printf("LARGEST SUFFIX %d : %s | SIZE: %d \n", largestSuffixIndex, suffixOfPrefix[largestSuffixIndex], largestSuffixSize);
            H[i] = largestSuffixIndex;
        }
        else
        {
            printf("NO PREFIX FOUND FOR SUFFIX %s\n", suffixOfPrefix[i]);
            H[i] = 0;
        }
    }
}