#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d inserted\n", value);
    }
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("underflow (empty queue)\n");
    } else {
        printf("%d element deleted\n", queue[front]);
        front++;
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("empty\n");
    } else {
        printf("\nprinting queue\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}
void demonstrateOverflowUnderflow() {
    front = -1;
    rear = -1;

    printf("\n Demonstrating Overflow \n");
    for (int i = 1; i <= MAX + 1; i++) {
        if (rear == MAX - 1) {
            printf("overflow\n");
        } else {
            if (front == -1)
                front = 0;
            rear++;
            queue[rear] = i * 10; 
        }
    }
    printf("\n--- Demonstrating Underflow ---\n");
    for (int i = 1; i <= MAX + 1; i++) {
        if (front == -1 || front > rear) {
            printf("underflow\n");
        } else {
            front++; 
        }
    }
}
int main() {
    int value, choice;

    while (1) {
        printf("\n1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("4.demonstrate overflow/underflow\n");
        printf("5.exit\n");
        printf("enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("enter the number: ");
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
                demonstrateOverflowUnderflow();
                break;

            case 5:
                printf("exiting..\n");
                exit(0);

            default:
                printf("invalid input\n");
        }
    }
    return 0;
}
