# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>

# define MAX_WORD_SIZE 100

typedef struct item
{
    char data[MAX_WORD_SIZE];
    long freq;

} Item;

// reads the file and populates Item
void readFile(char* fileName, Item* items, int* n);
void populateItem(char* data, Item* items, int* n);
void printItem(Item item);
void printItems(Item* items, int n);
int compareItem(const void* it1, const void*  it2);
