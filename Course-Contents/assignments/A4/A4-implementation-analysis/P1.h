# ifndef P1UTILS_H
# include "P1utils.h"
# endif


// Table Data Structure
typedef struct tableCell
{
    double cost;
    int root;
} TableCell;

// top-level api
void p11(Item* items, int n, char* pattern);
void p12(Item* items, int n, char* pattern);


void printTableCell(TableCell cell);
void printTable(int rows, int cols, TableCell** table);


/**
 * Creating Optimal Binary Search Tree with Dynamic Programming
 * **/
// create cost table with associated roots
// assumes items are 1 indexed [1..n], i.e. size N = n+1
// Table has rows: n+2 and cols: n+1
// ROWS: [0..n+1] rows of which [1..n+1] are useful 
// COLS: [0..n] columns
void createCostTable(Item* items, int N, TableCell** costTable, int* rows, int* cols);

// creates optimum binary search tree from items provided 
// assumes items are 1 indexed
TreeNode* createSubtreeRecursiveFromTable(Item* items, int N, int L, int R, TableCell** costTable, int rows, int cols);
TreeNode* createTreeFromTable(Item* items, int N, TableCell** costTable, int rows, int cols);
TreeNode* createOBSTDP(Item* items, int N);

/**
 * Creating Optimal Binary Search Tree with Greedy Technique
 * **/
TreeNode* createOBSTGreedy(Item* items, int N);
TreeNode* createSubtreeRecursiveGreedy(Item* items, int N, int totalFrequency, int L, int R);
TreeNode* createTreeFromSortedSequence(Item* items, int N);
