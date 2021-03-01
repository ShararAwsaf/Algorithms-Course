# ifndef P1_H
# include "P1.h"
# endif

void p11(char* p, char** T, int TL)
{
    printf("Running Brute Force Anagram Search \n");

    struct timeval startTime, endTime;

    printf("______________ANAGRAMS______________\n\n");
    gettimeofday(&startTime, NULL);
    int anagrams = brute_force_anagram_search(p, T, TL);
    gettimeofday(&endTime, NULL);
    printf("____________________________________\n");
    printf("Number of Anagrams: %d\n", anagrams);
    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);

    totalRunTime /= 1000;

    printf("Total Time to Run: %f ms\n", totalRunTime);
}

int sequential_search_anagram(char* t, char* p)
{   
    int m = strlen(p);
    int n = strlen(t);
    // sizes don't match then not anagram
    if( m != n)
        return -1;
 

    // tracks which characters have been previously hit
    int matched_characters[MAX_SIZE];
    for(int i=0; i<n; i++)
    {
        matched_characters[i] = 0;
    }

    for(int i=0; i<m; i++)
    {
        // try searching each letter in the string
        for(int j=0; j<strlen(t); j++)
        {
            // if match found with a previously unfound character
            if(t[j] == p[i] && matched_characters[j] == 0)
            {
                matched_characters[j] = 1; // mark that character as found
                break;
            }
        }
    }

    // check if all the characters were hit and the source and pattern are not the exact same
    int search_matches=0;
    int same_as_pattern = 1;
    
    while(search_matches<n && matched_characters[search_matches] == 1)
    {
        if(same_as_pattern == 1 && p[search_matches] != t[search_matches])
        {
            same_as_pattern = 0;
        }

        search_matches++;
    }

    if(search_matches == n)
    {
        if(!same_as_pattern)
            return 1;
        
        return 0;
    }
    
    return -1;
}

int brute_force_anagram_search(char* P, char** T, int TL)
{
    int anagrams  = 0;
    for(int t = 0; t<TL; t++)
    {
        int match = sequential_search_anagram(T[t], P);
        if(match > 0)
        {
            anagrams += 1;
            printf("%d. %s\n", anagrams, T[t]);
        }
    }

    return anagrams;
}