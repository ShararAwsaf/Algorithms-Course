# ifndef P1_H
# include "P1.h"
# endif

void p11(Item* items, int n)
{

    printf("Running OBST using Dynamic Programming....\n");

    // printItems(items, n); // items is 1 indexed
    
    TreeNode* obst = NULL;
    createOBST(items, n, obst);


}

void createOBST(Item* items, int N, TreeNode* obst)
{
    
    printItem(items[1]);
    // sort items
    qsort(items, N, sizeof(Item), compareItem);
    printItems(items, N); // items is 1 indexed

    // create table
    TableCell** costTable = malloc(sizeof(TableCell*)*MAX_TABLE_SIZE);
    int n = N-1;
    int rows = n+2;
    int cols = n+1;

    for(int i=0; i<rows; i++)
    {
        costTable[i] = malloc(sizeof(TableCell)*MAX_TABLE_SIZE);

        for(int j=0; j<cols; j++)
        {
            costTable[i][j].cost = 0;
            costTable[i][j].root = -1;
        }
    }
    
    // // initialize table
    for(int i=1; i< n+1; i++)
    {
        
        costTable[i][i-1].cost = 0;
        costTable[i][i-1].root = -1;

        costTable[i][i].cost = items[i].freq;
        costTable[i][i].root = i;

        // printf("i: %d | ", i);
        // printTableCell(costTable[i][i]);
        // printf("\nExpected: ");
        // printItem(items[i]);


    }
    costTable[n+1][n].cost=0;
    costTable[n+1][n].root=-1 ;
    
    printTable(rows, cols, costTable);
}

void printTableCell(TableCell cell)
{
    // printf("Cost: %ld | Root: %d : ", cell.cost, cell.root);
    printf("[(%ld)(%d)] ", cell.cost, cell.root);

}

void printTable(int rows, int cols, TableCell** table)
{
    for(int r=0; r<rows; r++)
    {
        printf("%d) ", r);
        for(int c=0; c<cols; c++)
        {
            printTableCell( ( (TableCell*)table[r])[c]) ;
        }
        printf("\n");
    }

    printf("ROWS: %d | COLS: %d\n", rows, cols);
}

