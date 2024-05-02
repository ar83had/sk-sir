#include "tree.h"

typedef struct list
{
    int data;
    struct list* next;
}list;

list* inorder_list(tree*);
list* preorder_list(tree*);
void display(list*);
tree* copy(list*,list*,int);

int main()
{
    tree* root = NULL;
    root = tree_create(root);
    // list* in_start = inorder(root);
    list* in_start = inorder_list(root);
    printf("\ninorder(orignal)->");
    display(in_start);
    list* pre_start = preorder_list(root);
    printf("\npreorder(orignal)->");
    display(pre_start);

    int n;
    printf("\nenter Again number of nodes :");
    scanf("%d",&n);
    tree* root2 = copy(in_start,pre_start,n);~
    printf("\ninorder(copy) ->");
    inorder(root2);
    printf("\npreorder(copy)");
    preorder(root2);

    return 0;
}

list* insert_end(list* start,list* node)
{
    if(start == NULL)
        return node;

    list* ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = node;
    return start;
}
list* preorder_list(tree* root)
{
    if(root== NULL)
        return NULL;

    static list* start=NULL;
    list* newnode= (list*)malloc(sizeof(list));
    newnode->next = NULL;
    newnode->data = root->data;
    start = insert_end(start,newnode);
    list* temp= preorder_list(root->l_child);
    temp = preorder_list(root->r_child);
    return start;
}

void display(list* start)
{
    if(start == NULL)
        return;

    printf("->%d",start->data);
    display(start->next);
    return;
}

list* inorder_list(tree* root)
{
    if(root == NULL)
        return NULL;

    list* temp = inorder_list(root->l_child);

    static list* start = NULL;
    list* newnode = (list*)malloc(sizeof(list));
    newnode->next = NULL;
    newnode->data = root->data;
    start = insert_end(start,newnode);

    temp = inorder_list(root->r_child);
    return start;
}

tree* copy(list* inorder , list* preorder,int n)
{
    if(n==0)
        return NULL;
    
    tree* newnode = (tree*)malloc(sizeof(tree));
    newnode->data = preorder->data;
    newnode->l_child = NULL;
    newnode->r_child = NULL;

    if(n == 1)
        return newnode;

    list* temp = inorder;
    int c1=0;
    while(temp->data != preorder->data)
    {
        temp = temp->next;
        c1++;
    }

    newnode->l_child = copy(inorder,preorder->next,c1);

    int c2=0;
    while(c2<c1)
    {
        preorder= preorder->next;
        c2++;
    }

    newnode->r_child = copy(temp->next,preorder->next,n-c1-1);

    return newnode;
}