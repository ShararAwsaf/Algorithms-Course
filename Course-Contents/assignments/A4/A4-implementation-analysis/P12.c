# ifndef P1_H
# include "P1.h"
# endif

void p12(Item* items, int n, char* pattern)
{

    printf("Running OBST using Greedy Technique....\n");

    // printItems(items, n); // items is 1 indexed
    
    TreeNode* obst = NULL;
    obst = createOBSTGreedy(items, n);
    // TreeNode* tmpRoot = obst;
    printTreeInOrder(obst);

    int r = searchOBST(pattern, obst);

    if(r == 0)
        printf("found '%s'\n", pattern);
    else
        printf("Not found '%s'\n", pattern);

}

TreeNode* createOBSTGreedy(Item* items, int N)
{
    TreeNode* obst = NULL;
    // sort items
    qsort(items, N, sizeof(Item), compareItem);
    // printItems(items, N); // items is 1 indexed
    obst = createTreeFromSortedSequence(items, N);

    return obst;
}

TreeNode* createTreeFromSortedSequence(Item* items, int N)
{
    TreeNode* tree = NULL;
    tree = createSubtreeRecursiveGreedy(items, N, 0, N-1);
    return tree;
}

TreeNode* createSubtreeRecursiveGreedy(Item* items, int N, int L, int R)
{
    if (L > R)
    {
        return NULL;
    }

    int max_root_index = -1;
    int max_root_freq = -INT32_MAX;
    for(int i=L; i<=R; i++)
    {
        if (max_root_freq < items[i].freq)
        {
            max_root_freq = items[i].freq;
            max_root_index = i;
        }
    }
    // found max root (greedy)
    TreeNode* root = createTreeNode(items[max_root_index].data, NULL, NULL);

    root->leftSubtree = createSubtreeRecursiveGreedy(items, N, L, max_root_index-1);
    root->rightSubtree = createSubtreeRecursiveGreedy(items, N, max_root_index+1, R);

    return root;
}

int searchOBSTGreedy(char* searchItem, TreeNode* obst)
{
    return 0;
}