#include<stdio.h>

// implementatio of queueu using two stack;

int top=-1;
void dequeue_costly();
void push(int[],int el);
int pop(int []);
void display(int[]);
void enqueue_costly();

int main()
{
    //dequeue_costly();                           dequeue costly method ;

    enqueue_costly();

    return 0;
}

void dequeue_costly()
{
    int ch,stack1[10],stack2[10];
    do
    {
        printf("\n1)enque\n2)dequeue\nenter your choice :");
        scanf("%d",&ch);
        int el,index=0;

        switch(ch)
        {
            case 1:
                printf("\nenter the element :");
                scanf("%d",&el);
                push(stack1,el);
                break;
            case 2:
                while(top >= 0)
                    stack2[index++]=pop(stack1);
                top=index-1;
                int el = pop(stack2);
                printf("\n--->%d",el);
                index=0;
                while(top >= 0)
                    stack1[index++]=pop(stack2);
                top=index-1;
                break;
        }
        display(stack1);
    } while (ch < 3);
    
}

void push(int stack[],int el)
{
    if(top == 9)
        printf("\nSTACK OVERFLOW !!!");
    else
        stack[++top] = el;
    return;
}

int pop(int stack[])
{
    if(top == -1)
        printf("\nSTACK UNDERFLOW !!!");
    else
        return stack[top--];
    return -1;
}

void display(int stack[])
{
    int c1=0;
    printf("\n");
    while(c1 <= top)
        printf("%5d",stack[c1++]);
    return;
}

void enqueue_costly()                                                //the code was 95% work;
{ 
    int ch,stack1[10],stack2[10];
    do
    {
        printf("\n1)enqueue\n2)dequeue\n3)display\nenter your choice :");
        scanf("%d",&ch);

        int el,index=0;
        switch(ch)
        {
            case 1:
                printf("\nenter the element :");
                scanf("%d",&el);

                if(top == -1)
                    push(stack1,el);
                else
                    while(index <= top)
                        stack2[index++]=pop(stack1);
                
                printf("%d",index);
                top=--index;
                printf("%d",index);
                index=0;

                if(index==0)
                    stack1[index++]=el;

                while(top >= 0)
                {
                    printf("%d%d",top,index);
                    stack1[index++]=pop(stack2);
                }

                top = --index;
                break;

            case 2:
                el=pop(stack1);
                printf("\n--->%d",el);
                break;
            case 3:
                display(stack1);
                break;
        }
        display(stack1);
    } while (ch <= 3);
    
}