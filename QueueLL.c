#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value);
void dequeue();
void display();

int main() {
    int choice, value;
    printf("\n:: Queue Implementation using Linked List:\n");
    while (1) {
        printf("\n*MENU***\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong selection! Please try again.\n");
        }
    }
    return 0;
}

void enqueue(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\nInsertion is successful!\n");
}

void dequeue() {
    if (front == NULL) {
        printf("\nQueue is empty!\n");
        return;
    }
    struct Node *temp = front;
    front = front->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
    if (front == NULL) {
        rear = NULL;
    }
}

void display() {
    if (front == NULL) {
        printf("\nQueue is empty!\n");
    } else {
        struct Node *temp = front;
        printf("Queue Data: ");
        while (temp != NULL) {
            printf("%d", temp->data);
            if (temp->next != NULL) {
                printf(" -> ");
            }
            temp = temp->next;
        }
        printf("\n");
    }
}
