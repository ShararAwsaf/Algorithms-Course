# include <string.h>

# define MAX_WORD_SIZE 100

typedef struct item
{
    char data[MAX_WORD_SIZE];
    long freq;

} Item;

// reads the file and populates Item
void readFile(char* fileName, Item* items, int* N);
int populateFrequency(Item* items, int n);
int create1indexedArray(Item* items, int n, Item* newItemArray, int* N);