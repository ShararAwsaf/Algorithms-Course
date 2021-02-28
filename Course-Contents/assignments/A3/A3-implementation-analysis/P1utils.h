# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# ifndef MAX_SIZE_CONST
# define MAX_SIZE 50000
# define MAX_WORD_SIZE 100

# endif

typedef struct word
{
    int initial_index;
    char word[MAX_WORD_SIZE];
    int word_value;

} Word;

void print_words(Word* words, int len);
void print_word(Word word);
void get_text_P1(char* datapath, char** T, int* TL);
void print_text_P1(char** T, int TL);


// generates an integer based signature of a string s and stores it into the integer array d
void generate_signature(char* s, char* d);

int compare_words(const void* w1, const void* w2);
