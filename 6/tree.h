#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int data;
    struct tree* l_child,*r_child;
}tree;

tree* tree_create()
{
    int n;
    printf("\nenter number of node :");
    scanf("%d",&n);
    tree* root = NULL;

    for(int c1=0;c1<n;c1++)
    {
        tree* newnode = (tree*)malloc(sizeof(tree));
        printf("\nenter %d node data :",c1+1);
        scanf("%d",&newnode->data);
        newnode->l_child=newnode->r_child=NULL;

        if(root == NULL)
            root = newnode;
        
        else
        {
            tree* ptr = root;
            tree* parent = NULL;
            while(ptr != NULL)
            {
                parent = ptr;
                if(ptr->data > newnode->data)
                    ptr = ptr->l_child;
                else if(ptr->data < newnode->data)
                    ptr = ptr->r_child;
                else
                {
                    printf("\nduplicate data is not allowed !");
                    break;
                }
            }

            if(ptr == NULL && parent->data > newnode->data)
                parent->l_child = newnode;
            else if(ptr == NULL)
                parent->r_child = newnode;
        }
    }
    return root;
}


void inorder(tree* root)
{
    if(root == NULL)
        return;
    
    inorder(root->l_child);
    printf("->%d",root->data);
    inorder(root->r_child);
    
    return;
}