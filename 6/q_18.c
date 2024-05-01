#include "tree.h"

//count number of leaf node;

int tree_leafnode(tree*,int);

int main()
{
    tree* root = tree_create();
    inorder(root);
    printf("\nleaf node ->");
    int re = tree_leafnode(root,0);
    printf("\nNumber Of Leaf node -> %d",re);
    return 0;
}

int tree_leafnode(tree* root,int count)
{
    if(root == NULL)
    {
        return count;
    }

    count = tree_leafnode(root->l_child,count);
    if(root->l_child == NULL && root->r_child == NULL)
    {
        printf("->%d",root->data);
        return count+1;
    }
    count = tree_leafnode(root->r_child,count);
    return count;
}
