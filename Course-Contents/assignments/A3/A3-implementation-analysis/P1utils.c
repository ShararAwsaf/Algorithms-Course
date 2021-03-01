# ifndef P1UTILS_H
# include "P1utils.h"
# endif

int compare_characters(const void* c1, const void* c2)
{
    return *(char*)c2 - *(char*)c1; // sorting in descending to put 0s to the end in case value based comparisons are made
}

int compare_words(const void* w1, const void* w2)
{
    return ( (*(Word*)w2).word_value - (*(Word*)w1).word_value );
}

void generate_signature(char* s, char* d)
{
    strcpy(d, s);
    qsort(d, strlen(s), sizeof(char), compare_characters);
}

void print_words(Word* words, int len)
{
    for(int i=0; i<len; i++)
    {
        print_word(words[i]);
    }
}

void print_word(Word w)
{
    printf("I: %d | V: %s\n", w.initial_index, w.word);
}

void get_text_P1(char* datapath, char** T, int* TL)
{
    FILE* fptr = fopen(datapath, "r");
    int i = 0;
    int j = 0;
    int prev = -1;
    char c;

    while(fread(&c, 1, 1, fptr))
    {
        // printf("%c",c);
        // printText(T, i+1);
        if(c == '\n')
        {
            // skips new lines
        }
        else if(c == ' ')
        {
            T[i][j]='\0'; // end previous word
            i += 1;
            j = 0;   
        }
        else
        {
            if(i > prev)
            {
                T[i] = malloc(sizeof(char)*MAX_SIZE); // create a new line
                prev = i;
            }

            T[i][j] = c;
            j += 1;
        }
    }
    *TL = i;
    fclose(fptr);
}


void print_text_P1(char** T, int TL)
{
    for(int i=0; i< TL; i++)
    {
        printf("%d. %s\n", i+1, T[i]);
    }
}
