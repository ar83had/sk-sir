#include<stdio.h>
#include"linked_list.h"

// find the nth term from the end of the list (with count number of node and reverse the node);

void nth_term_end(coust*);

int main()
{
    coust* node,*fix=NULL;
    while(1)
    {
        char ch;
        printf("\ninsert a node(y/n) :");
        scanf("\n%c",&ch);
        if(ch == 'n')
            break;
        node=input();
        start = insert(start,node);
    }
    
    fix=start;
    printf("\nbefore funcation call:-");
    display(start);

    nth_term_end(start);

    return 0;
}

void nth_term_end(coust* start)
{
    int n;
    printf("\nenter positin from end of list :");
    scanf("%d",&n);

    if(!n)
    {
    printf("\nthe finded node is :-");
    printf("\n coustomer id = %d\n name  = %s \nage = %d",start->c_id,start->name,start->age);
    }

    while(start != NULL)
    {
        coust* temp= start;
        for(int c1=0;c1<n;c1++)
            temp = temp->link;
        
        if(temp == NULL)
        {
            printf("\nthe finded node is :-");
            printf("\n coustomer id = %d\n name  = %s \nage = %d",start->c_id,start->name,start->age);
            return;
        }
        start =start->link;
    }
}