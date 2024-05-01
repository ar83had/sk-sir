#include "tree.h"

int min_height(tree*,int);

int main()
{
    tree* root = NULL;
    root = tree_create(root);
    inorder(root);

    int re = min_height(root,-1);
    printf("\n%d",re);
    return 0;
}

int min_height(tree* root,int count)
{
    if(root==NULL)
        return count;
    
    count++;
    int l_h = min_height(root->l_child,count);
    int r_h = min_height(root->r_child,count);

    if(l_h >= r_h)
        count = r_h;

    return count;
}