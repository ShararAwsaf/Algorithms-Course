# ifndef P2_H
# include "P2.h"
# endif


void p22(char* p, char* T)
{
    printf("Running Horspool's String Search\n");
    printf("Input Size: %lu\n", strlen(T));
    struct timeval startTime, endTime;

    gettimeofday(&startTime, NULL);
    int matches = HorsPoolStringMatching(p, T);
    gettimeofday(&endTime, NULL);
    
    printf("Total Matches: %d\n", matches);

    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);

    totalRunTime /= 1000;

    printf("Total Time to Run: %f ms\n", totalRunTime);
}

void creatShiftTable(char* P, int* ShT, int ShTL)
{
    int m = strlen(P);
    for(int i=0; i<ShTL; i++)
        ShT[i] = m;

    for(int j=0; j<m-1; j++)
        ShT[(int)P[j]] = m - 1 - j;
}

int HorsPoolStringMatching(char* P, char* T)
{
    int m = strlen(P);
    int n = strlen(T);

    int HTB[TABLE_SIZE];
    int HTBL = TABLE_SIZE;

    creatShiftTable(P, HTB, HTBL);
    // printTable(HTB, HTBL);
    int i = m-1;

    int matches = 0;
    int shifts = 0;

    while(i <= n-1)
    {
        shifts+=1;

        // Skip bad symbols since they are not in pattern
        if((int)T[i] < 0 || (int)T[i] >= TABLE_SIZE)
        {
            i+=m;
            continue;
        }
        int k = 0;

        while(k <= m-1 && P[m-1-k] == T[i-k]) // i stays at the highest position
        {
            k += 1;
        }

        if(k == m) // in case of a match i skips to another highest position
        {
            matches += 1;
            i += m; // Skip to the next word length since the word completely matches
        }
        else // in case of mismatch i skips as much permitted by table
        {
            i = i + HTB[(int)T[i]];
        }
        
    }

    printf("Pattern shifts: %d\n", shifts);
    return matches;
}

void printTable(int* TB, int TBL)
{
    for(int i=0; i< TBL; i++)
        printf("K: %d (%c) | V: %d\n", i, (char)i, TB[i]);
}