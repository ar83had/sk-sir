#include<stdio.h>
#include<stdlib.h>

typedef struct coustomer
{
    char name[20];
    int age,c_id;
    struct coustomer* link;
}coust;
coust* start;
coust* input()
{
    coust* node = (coust*)malloc(sizeof(coust));
    printf("\ncoustomer id = ");
    scanf("%d",&node->c_id);
    printf("name = ");
    scanf("\n");
    gets(node->name);
    printf("age = ");
    scanf("%d",&node->age);
    node->link=NULL;
    return node;
}

void display(coust* start)
{
    int n=1;
    while(start != NULL)
    {
        printf("\ndetails of %d coustomer:-",n++);
        printf("\ncoustomer id = %d \nname = %s \nage = %d ",start->c_id,start->name,start->age);
        start = start->link;
    }
    return;
}

coust* insert(coust* start,coust* node)
{
    coust* fix=start;
    if(start == NULL || start->c_id > node->c_id)
    {
        node->link = start;
        return node;
    }

    else
    {
        while(start->link != NULL && start->link->c_id < node->c_id)
            start = start->link;
        node->link = start->link;
        start->link = node;
        return fix;
    }
}





