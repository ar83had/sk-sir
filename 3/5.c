#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linked_list.h"

//create a reverse list of list "L" ,without affecting the list L.

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
    printf("/nthis is main list:-");
    display(start);
    coust* new_list=NULL,*fix_new=NULL,*end=NULL,*fix=start;

    while(fix != end)
    {
        start = fix;
        while(start->link != end)
            start= start->link;

        node=(coust*)malloc(sizeof(coust));
        node->c_id=start->c_id;
        strcpy(node->name,start->name);
        node->age=start->age;
        node->link=NULL;

        if(new_list==NULL)
            new_list=fix_new=node;
        else
        {  
            new_list->link = node;
            new_list=new_list->link;
        }
        
        end = start;
    }
    start = fix,new_list=fix_new;

    printf("\nthis is reverse list:-");
    display(new_list);
    

    return 0;
}
