#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist
{
	int data;
	struct linkdlist* next;
}list;
list* fix=NULL;

list* insert(list*,list*);
void display();
void sel_short();
void link_short();

int main()
{
	list* start=NULL;
	while(1)
	{
		char ch;
		printf("\n insert a node (y/n):");
		scanf("\n%c",&ch);
		
		if(ch=='n')
			break;
			
		list* node=(list*) malloc(sizeof(list));
		printf("\nenter the node data :");
		scanf("%d",&node->data);
		node->next=NULL;
		
		start = insert(start,node);
    }
	
	printf("\ninserted list :-");
	display();	
	
	link_short();
	printf("\nafter the shorting");
	display();
	
	return 0;
}

list* insert(list* start,list* node)
{
	if(start==NULL)
		fix=start=node;
	else
	{
		start->next=node;
		start=start->next;
    }
    
    return start;
}

void display()
{
	list* temp=fix;
	while(temp!=NULL)
	{
		printf("->%d",temp->data);
		temp=temp->next;
    }
    return;
}

void sel_short()
{
	list* start=fix;
	while(start != NULL && start->next!= NULL)
	{
		list* temp=start->next;
		
		while(temp != NULL)
		{
			if(start->data > temp->data)
			{
				int temp2=start->data;
				start->data = temp->data;
				temp->data = temp2;
			}
			temp=temp->next;
		}
		
		display();
		start=start->next;
    }
    return;
}

void link_short()
{
	list*p,*q,*r,*s;
	p=r=fix;
	while(p->next != NULL)
	{
		q=s=p->next;
		list* temp;
		while(q!=NULL)
		{
			if(p->data > q->data)
			{
				temp=p;
				if(p==fix)
					fix=p=r=q;
				else
				{
					r->next = q;
					s->next=p;
			    }
					
				temp = p->next;
				p->next = q->next;
				q->next = temp;

				temp=p;
				p=q;
				q=temp;
			}

			s=q;
			q=q->next;
		}
		r=p;
		p=p->next;
	}
		return;
}
