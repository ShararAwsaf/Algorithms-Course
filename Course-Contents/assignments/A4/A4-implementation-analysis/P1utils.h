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
    double probability;
    struct treeNode* leftSubtree;
    struct treeNode* rightSubtree;
} TreeNode;


void printTreeInOrder(TreeNode* tree);
void printTreeNode(TreeNode* node);
TreeNode* createTreeNode(char* string, double probabillity, TreeNode* leftSubTree, TreeNode* rightSubTree);

// search tree for item, print steps along the way
// return 0 for found else not found
int searchOBST(char* searchItem, TreeNode* obst);