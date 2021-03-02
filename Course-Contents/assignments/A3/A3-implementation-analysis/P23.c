# ifndef P2_H
# include "P2.h"
# endif

void p23(char* p, char* T)
{
    printf("Running Boyer-Moore's String Search\n");
    printf("Input Size: %lu\n", strlen(T));
    printf("Pattern Size: %lu\n", strlen(p));

    struct timeval startTime, endTime;

    gettimeofday(&startTime, NULL);
    int matches = BoyerMooreStringMatching(p, T);
    gettimeofday(&endTime, NULL);
    
    printf("Total Matches: %d\n", matches);

    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);

    totalRunTime /= 1000;

    printf("Total Time to Run: %f ms\n", totalRunTime);
}

int BoyerMooreStringMatching(char* P, char* T)
{
    int matches = 0;
    int m = strlen(P);

    int* GST = malloc(sizeof(int)*m);
    int GSTL = m;
    createGoodSuffixTable(P, GST, GSTL);

    int BST[TABLE_SIZE];
    int BSTL = TABLE_SIZE;

    creatShiftTable(P, BST, BSTL);
    
    // Print the Bad symbol and Good Suffix Tables
    // printTable(BST, BSTL);
    // printGoodSuffixTable(GST, GSTL, P);


    int n = strlen(T);
    int shifts = 0;

    int i = m-1;
    while(i <= n-1)
    {

        // shifts+=1; // should we always increase, or only when the skip is taking place

        // Skip bad symbols since they are not in pattern
        if((int)T[i] < 0 || (int)T[i] >= TABLE_SIZE)
        {
            i+=m;
            shifts+=1;
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
            int skip = 1;
            int d1 = max(BST[(int)T[i-k]]-k, 1);
            int d2 = GST[k];

            if(k==0)
                skip = d1;
            else
                skip = max(d1, d2);
            // printf("k: %d | d1: %d | d2: %d | skip: %d (%c)\n", k, d1, d2, skip, T[i-k]);
            i = i + skip;
            shifts+=1;

        }

    }

    printf("Pattern shifts: %d\n", shifts);
    return matches;
}


void get_suffix(char* P, int PL, int suffix_start, char* suffix)
{
    int j = 0;
    for(int i=suffix_start; i < PL; i++)
    {
        suffix[j++] = P[i];
    }
    suffix[j] = '\0';
}

void get_prefix(char* P, int prefix_end, char* prefix)
{
    int j = 0;
    for(int i=0; i < prefix_end; i++)
    {
        prefix[j++] = P[i];
    }
    prefix[j] = '\0';
}

// not preceded by the same character
int search_right_most_suffix(char* to_search, int to_search_len, char* key, int key_len, char forbidden_char)
{
    int search_index = -1;
    for(int i=to_search_len-key_len; i >= 0; i--)
    {
        int j = i;
        int k = 0;
        while(j-i < key_len && key[k] == to_search[j])
        {
            j ++;
            k ++;
        }
        if(j-i == key_len && (i == 0 || to_search[i-1] != forbidden_char)) // found rightmost occurance
        {
            search_index = i;
            break;
        }
    }

    return search_index;
}


void createGoodSuffixTable(char* P, int* GSTB, int GSTBL)
{
    int m = strlen(P);
    GSTB[0] = -1;

    for(int k = m-1; k>0; k--)
    {
        int current_longest_suffix_shift = m;

        // in pref_k search for occurrance of suff_k
        // find rightmost occurrance (in case of multiple occurance)

        char* suff_k = malloc(sizeof(char)*m);
        char* pref_k = malloc(sizeof(char)*m);
    
        get_suffix(P, m, k, suff_k);
        get_prefix(P, k, pref_k);

        // printf("K: %d\n", m-k);
        // printf("PREFIX: %s | SUFFIX: %s\n", pref_k, suff_k);
        int search_index = search_right_most_suffix(pref_k, k, suff_k, m-k, P[k-1]);
        if(search_index >= 0)
        {
            
            int distance_from_suffix = 0;
            int suffix_location = k;
            while(suffix_location != search_index)
            {
                distance_from_suffix += 1;
                suffix_location -= 1;
            }
            
            current_longest_suffix_shift = distance_from_suffix;   
        }
        else // the suff(k) did not occur or the preceeding character matched on occurrance
        {
            for(int l=m-k-1; l >=0; l--)
            {
                char* suff_l = malloc(sizeof(char)*m);
                char* pref_l = malloc(sizeof(char)*m);
                get_suffix(P, m, m-1-l, suff_l);
                get_prefix(P, l+1, pref_l);
                // printf(">> l: %d | [prfx: %s | sufx: %s ] ", l, pref_l, suff_l);
                if(strcmp(pref_l, suff_l) == 0)
                {
                    current_longest_suffix_shift = m- l - 1;
                    break;
                }
            }
            // printf("\n");
        }

        GSTB[m-k] = current_longest_suffix_shift;

    }
}

void printGoodSuffixTable(int* TB, int TBL, char* P)
{
    printf("\n--------GOOD SUFFIX TABLE--------\n");
    int m = strlen(P);
    for(int i=0; i<TBL; i++)
    {
        printf("k: %d | pattern: ", i);
        printSuffix(P, m, m-i);
        printf(" | d2: %d\n", TB[i]);

    }
    printf("---------------------------------\n");
}

void printSuffix(char* s, int sl, int suffixStart)
{
    for(int i=suffixStart; i<sl; i++)
    {
        printf("%c", s[i]);
    }
}