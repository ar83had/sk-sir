#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char stack[1000000];
char operations[1000][1000];
int top=-1;
int stack2[10000];
int top2 =-1;

void push(char,char[]);
void pop(int);
void display(int);
void undo(int,char[][1000]);

int main() {

    int n;
    scanf("%d",&n);
    
    for(int c1=0;c1<n;c1++)
    {
        scanf("\n");
        scanf("%[^\n]s",operations[c1]);
    }
    
    int undo_int=0;
    for(int c1=0;c1<n;c1++)
    {
        char type = operations[c1][0];
        switch(type)
        {
            case '1':
                push(operations[c1][0],&operations[c1][2]);
                stack2[++top2]= c1;
                break;
            case '2':
                pop(operations[c1][2]-'0');
                stack2[++top2]= c1;
                break;
            case '3':
                display(operations[c1][2]-'0');
                break;
            case '4':
                undo(stack2[top2--],operations);
                break;
        }
        
        int c2=0;
        printf("\n");
        while(c2 <= top)
        {
            printf("%c",stack[c2++]);
        }
    }
    
    return 0;
}

void push(char op,char str[])
{
    if(top == 999999)
    {
        return;
    }
    
    int c1=0;
    while(str[c1]!=0)
    {
        stack[++top]=str[c1++];
    }
    return;
}

void pop(int n)
{
    while(n>0 && top-n+1 >= 0)
    {
        top--;
        n--;
    }
    return;
}


void display(int n)
{
    printf("\n%c",stack[n-1]);
    return;
}

void undo(int n,char opeartion[][1000])
{
    if(operations[n][0] == '1')
    {
        int length=2;
        while(operations[n][length] != 0)
        {
            length++;
        }
        length -= 2;
        top -= length;
    }
    else if(operations[n][0] == '2')
    {
        top += (opeartion[n][2]-'0');
    }
    
    return;
}
