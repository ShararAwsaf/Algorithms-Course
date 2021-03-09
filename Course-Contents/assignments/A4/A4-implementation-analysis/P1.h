# include <stdio.h>
# include <ctype.h>
# include <sys/time.h>
# include <stdlib.h>
# include <math.h>

# ifndef UTILS_H
# include "utils.h"
# endif

# define MAX_SIZE 5000
# define MAX_TABLE_SIZE 680 // cannot make this too big

// Tree Data Structure
typedef struct treeNode
{
    char string[MAX_WORD_SIZE];
    struct treeNode* leftSubtree;
    struct treeNode* rightSubtree;
} TreeNode;

// Table Data Structure
typedef struct tableCell
{
    long cost;
    int root;
} TableCell;

// top-level api
void p11(Item* items, int n);

// helpers
void printTreeInOrder(TreeNode* tree);
void printTreeNode(TreeNode* node);
void printTableCell(TableCell cell);
void printTable(int rows, int cols, TableCell** table);
TreeNode* createTreeNode(char* string, TreeNode* leftSubTree, TreeNode* rightSubTree);

// create cost table with associated roots
// assumes items are 1 indexed [1..n], i.e. size N = n+1
// Table has rows: n+2 and cols: n+1
// ROWS: [0..n+1] rows of which [1..n+1] are useful 
// COLS: [0..n] columns
void createCostTable(Item* items, int N, TableCell** costTable, int* rows, int* cols);

// creates optimum binary search tree from items provided 
// assumes items are 1 indexed
TreeNode* findSubtreeRecursive(Item* items, int N, int L, int R, TableCell** costTable, int rows, int cols);
TreeNode* createTreeFromTable(Item* items, int N, TableCell** costTable, int rows, int cols);
TreeNode* createOBST(Item* items, int N);

// search tree for item, print steps along the way
// return 1 for find 0 for not found
int searchOBST(char* searchItem, TreeNode* obst);
