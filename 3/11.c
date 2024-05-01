#include<stdio.h>
#include"linked_list.h"

//delete the coustomer details which age has less than 18 or greater than 60;

coust* delete(coust*);

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
    printf("\nlist before deletion :-");
    display(start);

    start = fix = delete(start);
    display(start);
}

coust* delete(coust* start)
{
    coust* fix=start;
    while(start != NULL)
    {
        if(start == fix && !(start->age >= 18 && start->age<=60))
        {
            fix=start->link;
            free(start);
        }

        else if(start == NULL && !(start->age>= 18 && start->age <= 60))
        {
            free(start->link);
            start->link = NULL;
        }

        else if(!(start->link->age >= 18 && start->link->age <= 60))
        {
            coust* temp = start->link;
            start->link=start->link->link;
            free(temp);

        }
        start=start->link;
    }
    return fix;
}