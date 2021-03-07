# ifndef P2_H
# include "P2.h"
# endif

void p21(char* p, char* T)
{
    printf("Running Brute Force String Search\n");
    printf("Input Size: %lu\n", strlen(T));
    printf("Pattern Size: %lu\n", strlen(p));

    struct timeval startTime, endTime;

    gettimeofday(&startTime, NULL);
    int matches = brute_force_string_search(p, T);
    gettimeofday(&endTime, NULL);
    
    printf("Total Matches: %d\n", matches);

    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);

    totalRunTime /= 1000;

    printf("Total Time to Run: %f ms\n", totalRunTime);
}



int brute_force_string_search(char* P, char* T)
{
    int matches = 0;
    int n = strlen(T);
    int m = strlen(P);

    int shifts = -1; // since the first iteration is not a shift

    for(int i=0; ; i++)
    {        

        if(i+m > n)
            break;
            
        shifts += 1;

        int j = 0;
        while(j < m && T[i+j] == P[j])
        {
            j += 1;
        }
        if(j==m)
            matches += 1;
        // else // shift needed upon mismatch

    }

    printf("Pattern Shifts: %d\n", shifts);

    return matches;
}


