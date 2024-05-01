#include<stdio.h>
int stack[10],top=10;

//stack opreration from end of array;

void push(int);
int pop();
void display();

int main()
{
    int ch,el;
    do
    {
        printf("\n1)push\n2)pop\n3)exit\nenter the choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nenter the element :");
                scanf("%d",&el);
                push(el);
                break;
            case 2:
                el = pop();
                if(top!=10)
                    printf("\n-->%d",el);
                break;
        }
        display();
    }while(ch<3);
    printf("\nend");
    return 0;
}

void push(int el)
{
    if(top == 0)
    {
        printf("\nSTACK OVERFLOW !!!");
    }
    else
    {
        stack[--top]=el;
    }
    return;
}

int pop()
{
    if(top==10)
        printf("STACK UNDERFLOW !!!");
    else
        return stack[top++];
    return top;
}

void display()
{
    for(int c1=top;c1<10;c1++)
        printf("%3d",stack[c1]);
    return;
}