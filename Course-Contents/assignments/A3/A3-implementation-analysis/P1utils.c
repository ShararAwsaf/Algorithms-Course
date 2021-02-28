# ifndef P1UTILS_H
# include "P1utils.h"
# endif

int compare_characters(const void* c1, const void* c2)
{
    return *(char*)c1 - *(char*)c2;
}

int compare_words(const void* w1, const void* w2)
{
    return ( (*(Word*)w1).word_value - (*(Word*)w2).word_value );
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

