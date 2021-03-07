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

}

