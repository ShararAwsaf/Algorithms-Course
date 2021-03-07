# ifndef P1_H
# include "P1.h"
# endif

# define DEFAULT_FILE "./data/data_7.txt"

// headers
int driver(int argc, char** argv);


int main(int argc, char** argv)
{
    int result = driver(argc, argv);
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
    else if(argc > 4)
    {
        printf("Too many arguments passed\n");
        printf("Provide program name and file name (optional)\n");
        return -1;
    }

    int running = 0;
    void (*obstCreateFunc)(Item* , int ) = NULL;

    // program name transformation
    argv[1][0] = toupper(argv[1][0]);
    if(strcmp(argv[1], "P11") == 0)
    {
        running = 11;
        obstCreateFunc = &p11;
    }

    char* fileName = NULL;
    if(argc == 2)
        fileName = DEFAULT_FILE;
    else
        fileName = argv[2];
    printf("FILENAME: %s\n", fileName);

    // fill items (1 indexed fill-up)
    Item items[MAX_SIZE];
    strcpy(items[0].data, "\0");
    items[0].freq = 0;
    int n = 1;

    readFile(fileName, items, &n);    
    obstCreateFunc(items, n);

    return 0;
}