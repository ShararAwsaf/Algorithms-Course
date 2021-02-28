# include <stdio.h>
# ifndef IMPLEMENTATION_H
# include "implementation.h"
# endif

# define DEFAULT_FILE_P1 "./data/data_4.txt"
# define DEFAULT_FILE_P2 "./data/data_5.txt"

// HEADERS
int driver(int argc, char** argv);

// TESTS
void testSignature()
{
    char str[MAX_SIZE] = "8607154\0";
    char d[MAX_SIZE];
    generate_signature(str, d);
    printf("SOURCE: %s | DEST: %s\n", str, d);
}

void testWordSort()
{
    Word w1 = {.initial_index=0};
    Word w2 = {.initial_index=1};
    strcpy(w1.word, "456789");
    strcpy(w2.word, "123456");

    Word words[MAX_SIZE];
    words[0] = w1;
    words[1] = w2;

    printf("BEFORE\n");
    print_words(words, 2);
    qsort(words, 2, sizeof(Word), compare_words);
    printf("AFTER\n");
    print_words(words, 2);
}

int main(int argc, char** argv)
{
    int result = 0;

    // testSignature();
    // testWordSort();

    // main code to execute
    result = driver(argc, argv);

    return result;
}

int driver(int argc, char** argv)
{
    if (argc  <= 1)
    {
        printf("Too few arguments passed\n");
        printf("Provide program name and file name (optional)\n");
        return -1;
    }
    else if(argc > 3)
    {
        printf("Too many arguments passed\n");
        printf("Provide program name and file name (optional)\n");
        return -1;
    }

    int running = 0;
    void (*searchFunc)(char*, char**, int) = NULL;

    if(strcasecmp(argv[1], "P11") == 0)
    {
        running = 11;
        searchFunc = &p11;
    }
    else if (strcasecmp(argv[1], "P12") == 0)
    {
        running = 12;
        searchFunc = &p12;
    }
    else if (strcasecmp(argv[1], "P21") == 0)
    {
        running = 21;
        searchFunc = &p21;
    }
    else if (strcasecmp(argv[1], "P22") == 0)
    {
        running = 22;
        searchFunc = &p22;
    }
    else if (strcasecmp(argv[1], "P23") == 0)
    {
        running = 23;
        searchFunc = &p23;
    }
    
    char* fileName = NULL;

    if(argc == 2)
    {

        if (running / 10 == 1)
        {
            fileName = DEFAULT_FILE_P1;
        }
        else if(running / 10 == 2)
        {
            fileName = DEFAULT_FILE_P2;
        }
    }
    else
    {
        fileName = argv[2];
    }

    // read file
    char* T[MAX_SIZE];
    int TL = 0;
    printf("FILE: %s\n", fileName);
    getText(fileName, T, &TL);
    printText(T, TL);

    // prompt for a pattern
    printf("Enter Pattern to search: ");
    char pattern[MAX_SIZE];
    getPattern(pattern);
    printf("Searching for pattern '%s' in text\n", pattern);
    
    // search pattern
    searchFunc(pattern, T, TL);

    return 0;
}