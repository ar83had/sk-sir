#include "tree.h"

int is_identical(tree*,tree*);

int main()
{
    tree* root1 = tree_create(root1);
    tree* root2 = tree_create(root2);

    int re = is_identical(root1,root2);
    if(re)
        printf("\nINDENTICAL");
    else
        printf("\nNOT INDENTICAL");
    return 0;
}

int is_identical(tree* root1,tree* root2)
{
    if(root1 == NULL && root2 != NULL ||  root2 == NULL && root1 != NULL)
        return 0;

    int r1_l,r1_r,r2_l,r2_r;
    r1_l=r1_r=r2_l=r2_r=0;
    if(root1->l_child != NULL)
        r1_l=1;
    else if(root1->r_child != NULL)
        r1_r=1;

    if(root2->l_child != NULL)
        r2_l =1;
    else if(root2->r_child != NULL)
        r2_r = 1;

    static int flag = 1;
    if(!(r1_l == r2_l && r1_r==r2_r))
    {
        flag = 0;
        return flag;
    }

    flag = is_identical(root1->l_child , root2->l_child);
    flag = is_identical(root1->r_child,root2->r_child);

    return flag;
}