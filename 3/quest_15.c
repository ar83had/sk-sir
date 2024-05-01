#include<stdio.h>
#include"linked_list.h"

coust* move(coust*);

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

    printf("\nbefore forword move:-");
    display(start);

    start = move(start);

    printf("\nafter forword move:-");
    display(start);
    return 0;
}


coust* move(coust* start)
{
    coust* fix = start;
    int se;
    printf("\nenter the age :");
    scanf("%d",&se);

    if(start->age == se)
        printf("\nfirst\n");

    else
        while(start->link != NULL  && start->link->age != se)
            start = start->link;
    
    if(start->link == NULL)
    {
        printf("\n%d is not found!!",se);
        return fix;
    }

    coust* node = start;
    int n;
    printf("\nenter the move");
    scanf("%d",&n);

    start = start->link;
    for(int c1=1;start!= NULL && c1<=n;c1++)
        start = start->link;
    
    if(se == 0)
        return fix;
    else if(start == NULL)
    {
        printf("\ninvalid range!!!");
        return start;
    }
    else
    {
        if(node==fix && node->age == se)
        {
            printf("1");
            coust* temp1 = start->link;
            start->link = node;
            coust* temp2 = node->link;
            node->link = temp1;
            start = fix = temp2;
        }
        else
        {
        coust* temp2=node->link->link;
        coust* temp=start->link;
        start->link=node->link;
        node->link->link=temp;
        node->link = temp2;
        }
    }

    return fix;
}