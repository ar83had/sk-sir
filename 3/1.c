#include<stdio.h>
#include"linked_list.h"

//there we count frequency of age group people in linked list;

coust* short_list(coust*);
void frequency(coust*);

int main()
{
    coust*start=NULL,*node;;
    while(1)
    {   
        char ch;
        printf("\ninsert coustomer(y/n):-");
        scanf("\n%c",&ch);
        if(ch=='n')
            break;
        node=input();
        start = insert(start,node);
    }
    printf("\nshort base on id:-");;
    display(start);
    start = short_list(start);
    printf("\nshort base on age :-");
    display(start);
    frequency(start);
    return 0;
}

coust* short_list(coust* start)
{
    coust* p,*q,*r,*s,*temp;
    for(p = r=start;p->link != NULL;r=p,p=p->link)
    {
        for(q=s=p->link;q != NULL;s=q,q=q->link)
        {
            if(p->age > q->age)
            {
                coust* temp = p->link;
                p->link = q->link;
                q->link = temp;
                if(p!= start)
                    r->link = q;
                else
                    start = q;
                s->link = p;
                temp = p;
                p = q;
                q = temp;
            }
        }
    }
    return start;
}

void frequency(coust* start)
{
    while(start != NULL)
    {
        int count =1;
        while(start->link != NULL && start->age == start->link->age)
        {
            count++;
            start = start->link;
        }

        printf("\n%d age ---> %d",start->age,count);
        start = start->link;
    }
    return;
}