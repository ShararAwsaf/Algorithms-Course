# ifndef P1_H
# include "P1.h"
# endif

TreeNode* createTreeNode(char* string, double probabillity, TreeNode* leftSubTree, TreeNode* rightSubTree)
{
    TreeNode* node = malloc(sizeof(TreeNode));
    strcpy(node->string, string);
    node->probability = probabillity;
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
    printf("Compared with '%s'(%.4lf), ", obst->string, obst->probability);
    
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
        // found
    }
    
    return compare_result;
}