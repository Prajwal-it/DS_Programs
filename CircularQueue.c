#include<stdio.h>
#define MAX 5
int data[MAX],front,rear;
void initialize();
int full();
int empty();
void insertion();
void deletion();
void print();
void main()
{
    int ch;
    initialize();
    do{
    printf("Circular Queue Operations");
    printf("1.Insertion");
    printf("\n2.Deletion");
    printf("\n3.Print");
    printf("Enter choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:if(full()==0)
        {
            insertion();
        }
        else{
            printf("Queue is full");
        }
        break;
        case 2:if(empty()==0)
        {
            deletion();
        }
        else{
            printf("Queue is empty");
        }
        break;
        case 3:print();
        break;
        case 4:default:printf("You've entered an incorrect option");
    }
    }while(ch!=4);
}
void initialize()
{
    rear=front=-1;
}
int full()
{
    if(rear+1%MAX==front)
    {
        return (1);
    }
    else{
        return (0);
    }
}
int empty()
{
    if(rear==-1)
    {
        return(1);
    }
    else{
        return (0);
    }
}
void insertion()
{
    int x;
    printf("Enter data to insert");
    scanf("%d",&x);
    if(rear==-1)
    {
        rear=front=0;
        data[rear]=x;
    }
    else{
        rear=(rear+1)%MAX;
        data[rear]=x;
    }
}
void deletion()
{
    int x;
    x=data[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else{
        front=(front+1)%MAX;
        data[front]=x;
    }
    printf("Deleted Data:%d",x);
}
void print()
{
    int i;
    if(front==-1)
    {
        printf("Queue is Empty");

    }
    else{
        i=front;
        printf("\nQueue data");
        do{
            printf("\t%d",data[i]);
            i=(i+1)%MAX;
        }while(i!=rear);
        printf("\t%d",data[i]);
    }
}