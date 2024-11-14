#include <stdio.h>
#define MAX 5
int data[MAX], rear, front;
void initialize();
int empty();
int full();
void insertion();
void deletion();
void print();
int main()
{
    int ch;
    initialize();
    do
    {
        printf("\nQueue Operations:");
        printf("\n1.Insertion");
        printf("\n2.Deletion");
        printf("\n3.Print");
        printf("\nEnter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (full() == 0)
            {
                insertion();
            }
            else
            {
                printf("Queue is full");
            }
            break;
        case 2:
            if (empty() == 0)
            {
                deletion();
            }
            else
            {
                printf("Queue is empty");
            }
            break;
        case 3:
            print();
            break;
        case 4:
        default:
            printf("Invalid choice");
        }
    } while (ch != 4);
    return 0;
}
void initialize()
{
    rear = front = -1;
}
int full()
{
    if (rear == MAX - 1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
int empty()
{
    if (rear == -1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
void insertion()
{
    int x;
    printf("Enter data to insert:");
    scanf("%d", &x);
    if (rear == -1)
    {
        rear = front = 0;
        data[rear] = x;
    }
    else
    {
        rear = rear + 1;
        data[rear] = x;
    }
}
void deletion()
{
    int x;
    x = data[front];
    if (front == rear)
    {
        rear = front = -1;
    }
    else
    {
        front = front + 1;
    }
    printf("Deleted data:%d", x);
}
void print()
{
    int i;
    if (front == -1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        printf("Queue data:");
        for (i = 0; i <= rear; i++)
        {
            printf("\t%d", data[i]);
        }
    }
}