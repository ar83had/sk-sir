#include "tree.h"

void tree_anccesstor(tree*,int);

int main()
{
    tree* root =NULL;
    root  = tree_create(root);
    inorder(root);

    int se;
    printf("\nenter serach data :");
    scanf("%d",&se);
    tree_anccesstor(root,se);
    return 0;
}

void tree_anccesstor(tree* root,int se)
{
    if(root->data == se)
        return;
    
    if(root->data > se)
        tree_anccesstor(root->l_child,se);
    else
        tree_anccesstor(root->r_child,se);
    
    printf("->%d",root->data);
    return;
}