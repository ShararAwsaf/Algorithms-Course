# ifndef P1_H
# include "P1.h"
# endif

void p11(Item* items, int n)
{

    printf("Running OBST using Dynamic Programming....\n");

    // printItems(items, n); // items is 1 indexed
    
    TreeNode* obst = NULL;
    obst = createOBST(items, n);
    // TreeNode* tmpRoot = obst;
    printTreeInOrder(obst);

    char s[] = "undergraduate\0";
    int r = searchOBST(s, obst);
    
    printf("'%s' ", s);
    if(r == 0)
        printf("found\n");
    else
        printf("not found (%d)\n", r);

}

TreeNode* createOBST(Item* items, int N)
{
    
    // sort items
    qsort(items, N, sizeof(Item), compareItem);
    // printItems(items, N); // items is 1 indexed

    // create table
    TableCell** costTable = malloc(sizeof(TableCell*)*MAX_TABLE_SIZE);
    int rows = 0;
    int cols = 0;
    createCostTable(items, N, costTable, &rows, &cols);
    // printf("COST-TABLE (DP)\n");
    // printTable(rows, cols, costTable);
    
    return createTreeFromTable(items, N, costTable, rows, cols);
}

void createCostTable(Item* items, int N, TableCell** costTable, int* rows, int* cols)
{
    int n = N-1;
    (*rows) = n+2;
    (*cols) = n+1;

    for(int i=0; i<(*rows); i++)
    {
        costTable[i] = malloc(sizeof(TableCell)*MAX_TABLE_SIZE);

        for(int j=0; j<(*cols); j++)
        {
            costTable[i][j].cost = 0;
            costTable[i][j].root = -1;
        }
    }
    
    // initialize table
    for(int i=1; i< n+1; i++)
    {
        
        costTable[i][i-1].cost = 0;
        costTable[i][i-1].root = -1;

        costTable[i][i].cost = items[i].freq;
        costTable[i][i].root = i;

    }
    costTable[n+1][n].cost=0;
    costTable[n+1][n].root=-1 ;
    
    // printf("INITIALIZATION\n");
    // printTable( (*rows), (*cols), costTable);

    for(int d=1; d<n; d++)
    {
        // printf("D: %d\n", d);

        for(int i=1; i<n-d+1; i++)
        {
            int j = d+i;
            // printf("i: %d | j: %d\n", i ,j);
            int min_cost = INT32_MAX;
            int min_root = -1;

            for(int l=i; l<j+1; l++)
            {
                int cost = costTable[i][l-1].cost + costTable[l+1][j].cost;

                if (cost < min_cost)
                {
                    min_cost = cost;
                    min_root = l;
                }
            }

            int W = 0;
            for(int s=i; s<j+1; s++)
            {
                W += items[s].freq;
            }

            costTable[i][j].cost = min_cost + W;
            costTable[i][j].root = min_root;

        }

    }

}

TreeNode* findSubtreeRecursive(Item* items, int N, int L, int R, TableCell** costTable, int rows, int cols)
{
    int R_lr = costTable[L][R].root;

    TreeNode* node = createTreeNode(items[R_lr].data, NULL, NULL);

    // printf("L:%d R:%d\n", L, R);
    // printf("Going Left @ %s\n", node->string);
    if (R_lr-1 >= L)
        node->leftSubtree = findSubtreeRecursive(items, N, L, R_lr-1, costTable, rows, cols);

    // printf("Going Right @ %s\n", node->string);
    if (R >= R_lr+1)
        node->rightSubtree = findSubtreeRecursive(items, N, R_lr+1, R, costTable, rows, cols);

    // printf("Returning @ %s\n", node->string);
    return node;    
}

TreeNode* createTreeFromTable(Item* items, int N, TableCell** costTable, int rows, int cols)
{
    return findSubtreeRecursive(items, N, 1, N-1, costTable, rows, cols);

}


// Helpers
void printTableCell(TableCell cell)
{
    // printf("Cost: %ld | Root: %d : ", cell.cost, cell.root);
    printf("[(%ld)(%d)] ", cell.cost, cell.root);

}

void printTable(int rows, int cols, TableCell** table)
{
    // skips first row as it is not of any use
    for(int r=1; r<rows; r++)
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

TreeNode* createTreeNode(char* string, TreeNode* leftSubTree, TreeNode* rightSubTree)
{
    TreeNode* node = malloc(sizeof(TreeNode));
    strcpy(node->string, string);
    node->leftSubtree = leftSubTree;
    node->rightSubtree = rightSubTree;

    return node;
}

void printTreeNode(TreeNode* node)
{
    char d[MAX_WORD_SIZE];
    char l[MAX_WORD_SIZE];
    char r[MAX_WORD_SIZE];

    strcpy(d, "*");
    strcpy(l, "*");
    strcpy(r, "*");
    

    if(node != NULL && strlen(node->string))
        strcpy(d, node->string);

    if(node->leftSubtree != NULL && strlen(node->leftSubtree->string))
        strcpy(l, node->leftSubtree->string);

    if(node->rightSubtree != NULL && strlen(node->rightSubtree->string))
        strcpy(r, node->rightSubtree->string);

    printf("     %s\n%s          %s\n", d, l, r);
}

void printTreeInOrder(TreeNode* tree)
{

    if(tree != NULL)
    {
        printTreeNode(tree);
        printTreeInOrder(tree->leftSubtree);
        printTreeInOrder(tree->rightSubtree);
    }
    
}

int searchOBST(char* searchItem, TreeNode* obst)
{
    if(obst == NULL)
    {
        return -5;
    }

    int compare_result = strcmp(obst->string, searchItem);
    printf("Compared with '%s', ", obst->string);
    
    if(compare_result > 0)
    {
        printf("go to left subtree\n");
        compare_result = searchOBST(searchItem, obst->leftSubtree);

        
    }
    else if (compare_result < 0)
    {
        printf("go to right subtree\n");
        compare_result = searchOBST(searchItem, obst->rightSubtree);
    }
    else
    {
        printf("found '%s'\n", searchItem);
    }
    
    return compare_result;
}