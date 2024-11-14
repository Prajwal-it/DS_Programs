#include<stdio.h>
#define MAX 5
int data[MAX],top;
void initialize();
int empty();
int full();
void push();
void pop();
void print();
void main()
{
    int ch;
    initialize();
    do{
        printf("\nStack Operations:");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Print");
        printf("\4.Exit");
        printf("Enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:if(full()==0)
            {
                push();
            }
            else{
                printf("Stack is full");
            }
            break;
            case 2:if(empty()==0)
            {
                pop();
            }
            else{
                printf("Stack is empty");
            }
            break;
            case 3:print();
            break;
            default:printf("Invalid choice");
        }
    }while(ch!=4);
}
void initialize()
{
    top=-1;
}
int full()
{
    if(top==MAX-1)
    {
        return (1);
    }
    else{
        return (0);
    }
}
int empty()
{
    if(top==-1)
    {
        return (1);
    }
    else{
        return (0);
    }
}
void push()
{
    int x;
    printf("Enter data to insert:");
    scanf("%d",&x);
    top=top+1;
    data[top]=x;
}

void pop()
{
    int x;
    x=data[top];
    top=top-1;
    printf("Data poped:%d",x);
}

void print()
{
    int i;
    if(top==-1)
    {
        printf("\nStack is Empty");
    }
    else{
        printf("Stack data:");
        for(i=top;i>=0;i--)
        {
            printf("%d\t",data[i]);
        }
    }
}
