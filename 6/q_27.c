#include "tree.h"

tree* mirror(tree*);

int main()
{
    tree* root = tree_create();
    printf("\n");
    inorder(root);
    printf("\n");
    preorder(root);

    tree* root2 = mirror(root);
    printf("\n");
    inorder(root2);
    printf("\n");
    preorder(root2);

    return 0;
}

tree* mirror(tree* root)
{
    if(root == NULL)
        return NULL;
    
    tree* temp = root->l_child;
    root->l_child = root->r_child;
    root->r_child = temp;

    tree* temp2;
    temp2 = mirror(root->l_child);
    temp2 = mirror(root->r_child);

    return root;
}