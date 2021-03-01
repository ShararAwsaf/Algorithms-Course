# ifndef P1_H
# include "P1.h"
# endif

void p12(char* p, char** T, int TL)
{
    printf("Running Presorting Based Anagram Search \n");
    printf("Input Size: %d\n", TL);

    struct timeval startTime, endTime;

    gettimeofday(&startTime, NULL);
    int anagrams = presort_anagram_search(p, T, TL);
    gettimeofday(&endTime, NULL);
    printf("Number of Anagrams: %d\n", anagrams);
    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);

    totalRunTime /= 1000;

    printf("Total Time to Run: %f ms\n", totalRunTime);
}

int presort_anagram_search(char* P, char** T, int TL)
{
    int anagrams = 0;
    
    // presort
    // 1. sort individual strings
    Word signatureP;
    signatureP.initial_index = -1;
    generate_signature(P, signatureP.word);
    signatureP.word_value = atoi(signatureP.word);

    struct timeval startSortTime, endSortTime;
    Word signatureT[MAX_SIZE];
    gettimeofday(&startSortTime, NULL);
    for(int i=0; i<TL; i++)
    {
        signatureT[i].initial_index = i;
        generate_signature(T[i], signatureT[i].word);
        signatureT[i].word_value = atoi(signatureT[i].word);
    }

    // 2. sort the strings afterwards
    qsort(signatureT, TL, sizeof(Word), compare_words);
    gettimeofday(&endSortTime, NULL);

    
    float totalSortTime = (endSortTime.tv_sec - startSortTime.tv_sec) * 1000000 + 
		(endSortTime.tv_usec - startSortTime.tv_usec);

    totalSortTime /= 1000;

    // Search
    struct timeval startSearchTime, endSearchTime;
    gettimeofday(&startSearchTime, NULL);
                                                         // OTHER MODE OF SEARCH: bsearch(&signatureP, signatureT, TL, sizeof(Word), compare_words);
    printf("______________ANAGRAMS______________\n\n");
    for(int i=0; i<TL; i++)
    {
        if(signatureP.word_value == signatureT[i].word_value)
        {
            if(strcmp(T[signatureT[i].initial_index], P) != 0)
            {
                anagrams += 1;
                printf("%d. %s\n", anagrams, T[signatureT[i].initial_index]);
            }
        }    
    }
    printf("____________________________________\n");

    gettimeofday(&endSearchTime, NULL);

    float totalSearchTime = (endSearchTime.tv_sec - startSearchTime.tv_sec) * 1000000 + 
		(endSearchTime.tv_usec - startSearchTime.tv_usec);

    totalSearchTime /= 1000;
    printf("Sort Time: %f ms\n", totalSortTime);
    printf("Search Time: %f ms\n", totalSearchTime);

    return anagrams;
}