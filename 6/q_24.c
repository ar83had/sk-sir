#include "tree.h"


// create a tree and store preorder travertion in pre_start and inorder travertion in in_start;

// pending work --> copy/create tree with the help of inorder and preorde travertion;

typedef struct list
{
    int data;
    struct list* next;
}list;

list* inorder_list(tree*);
list* preorder_list(tree*);
void display(list*);

int main()
{
    tree* root = NULL;
    root = tree_create(root);
    // list* in_start = inorder(root);
    list* pre_start = preorder_list(root);
    printf("\n");
    display(pre_start);
    list* in_start = inorder_list(root);
    printf("\n");
    display(in_start);

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