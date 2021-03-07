# ifndef UTILS_H
# include "utils.h"
# endif

void readFile(char* fileName, Item* items, int* n)
{
    FILE* fptr = fopen(fileName, "r");

    if(fptr == NULL)
    {
        printf("File Not Found\n");
        return;
    }


    int i = 0;
    int j = 0;
    int prev = -1;
    char c;
    char* data = NULL;
    
    while(fread(&c, 1, 1, fptr))
    {
        if((c == '\n' || c == ' '))
        {
            if(i == prev)
            {
                data[j]='\0'; // end previous word
                populateItem(data, items, n);
                i += 1;
                j = 0;
            }
        }
        else
        {
            if(i > prev)
            {
                // static object needs no malloc
                data = malloc(sizeof(char)*MAX_WORD_SIZE); // create a new line
                
                prev = i;
            }

            data[j] = c;
            j += 1;
        }
    }
    fclose(fptr);
}

void populateItem(char* data, Item* items, int* n)
{
    // search for the item in the array of items
    for(int i=0; i<(*n); i++)
    {
        // if found increment frequency
        if(  strcmp(data, items[i].data) == 0  )
        {
            items[i].freq += 1;
            return;
        }
    }
    
    // if not found create a new item
    strcpy(items[(*n)].data, data);
    items[(*n)].freq = 1;

    // adjust size of array
    (*n) = (*n) +1;
}

void printItem(Item item)
{
    printf("D: %s | f(D): %ld\n", item.data, item.freq);
}

void printItems(Item* items, int n)
{
    int totalFreq = 0;
    for(int i=0; i< n; i++)
    {
        printf("%d) ", i);
        printItem(items[i]);
        totalFreq += items[i].freq;
    }
    printf("Total Unique Items: %d\n", n);
    printf("Total Frequency: %d\n", totalFreq);
}