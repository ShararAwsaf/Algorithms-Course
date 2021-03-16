# ifndef P1_H
# include "P1.h"
# endif

# define DEFAULT_FILE "./data/data_7.txt"

// headers
int driver(int argc, char** argv);
void get_pattern(char* p);

// tests
void testTablePrint();

int main(int argc, char** argv)
{
    int result = 0;
    result = driver(argc, argv);
    // testTablePrint();
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
    void (*obstCreateSearchFunc)(Item* , int , char*) = NULL;
    
    // Items to create tree and search
    Item items[MAX_SIZE];
    int n = 0;
    
    argv[1][0] = toupper(argv[1][0]); // program name transformation
    if(strcmp(argv[1], "P11") == 0)
    {
        running = 11;
        obstCreateSearchFunc = &p11;

        // P11: DP OBST requires 1 indexed array (so adding buffer to index 0)
        strcpy(items[0].data, "");
        items[0].freq = 0;
        n = 1;
    }
    else if(strcmp(argv[1], "P12") == 0)
    {
        running = 12;
        obstCreateSearchFunc = &p12;
    }
    else
    {
        printf("Please provide 'p11' or 'p12' as the program name\n");
        return -1;
    }

    char* fileName = NULL;
    if(argc == 2)
        fileName = DEFAULT_FILE;
    else
        fileName = argv[2];
    printf("FILENAME: %s\n", fileName);

    char pattern[MAX_WORD_SIZE];
    if(argc == 4)
        strcpy(pattern, argv[3]);
    else
        get_pattern(pattern);
    printf("PATTERN: %s\n", pattern);
    
    readFile(fileName, items, &n);
    
    obstCreateSearchFunc(items, n, pattern);

    return 0;
}

void testTablePrint()
{
    // create table
    TableCell** Table = malloc(sizeof(TableCell*)*MAX_TABLE_SIZE);
    int n = 2;
    
    int rows = n+2;
    int cols = n+1;
    for(int i=0; i<rows; i++)
    {
        Table[i] = malloc(sizeof(TableCell)*MAX_TABLE_SIZE);

        for(int j=0; j<cols; j++)
        {
            Table[i][j].cost = 22;
            Table[i][j].root = 45;
        }
    }

    Table[0][0] = (TableCell){ .cost=35, .root=27};
    printTableCell( ((TableCell*)Table[0]) [0]);
    printf("\n");

    printTable(rows, cols, Table);
}

void get_pattern(char* p)
{
    printf("Enter Pattern to search: ");

    scanf("%s", p);
}