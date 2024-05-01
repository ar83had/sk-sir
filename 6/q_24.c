#include "tree.h"

int main()
{
    tree* root = NULL;
    tree_create(root);
    INORDER(root);
    
    return 0;
}