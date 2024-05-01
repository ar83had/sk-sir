#include"linked_list.h"

// delete dublicate node from linked list;

void redendency_remove(coust*,int);

int main()
{
    int n;
    printf("enter the number of linked list :");
    scanf("%d",&n);
    
    coust*start,*fix;
    start = fix = NULL;
    for(int c1=0;c1<n;c1++)
    {
        coust* node = input();
        if(start == NULL)
            start = fix=node;
        else
        {
            start->link = node;
            start = start->link;
        }
    }

    start = fix;
    printf("\nbefore deletion:-");
    display(start);

    redendency_remove(start,n);
    printf("\nafter deletion :-");
    display(start);
    return 0;
}

void redendency_remove(coust* start,int n)
{
    int arr[n];
    arr[0] = start->c_id;
    int c1,count=1;

    while(start->link != NULL)
    {
        for(c1=0;start->link != NULL && c1<count;c1++)
        {
            if(start->link->c_id == arr[c1])
                break;
        }

        if(c1==count)
        {
            arr[count++] = start->link->c_id;
            start =start->link;
        }

        else
        {
            coust* temp = start->link;
            start->link = start->link->link;
            free(temp);
        }
    }

    return;

}
