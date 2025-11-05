#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed into stack\n", value);
    }
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}
void palindromeCheck() {
    int num, temp, digit;
    int rev = 0;
    int tempStack[MAX];
    int tempTop = -1;

    printf("Enter a number to check palindrome: ");
    scanf("%d", &num);
    temp = num;

    while (temp > 0) {
        digit = temp % 10;
        if (tempTop == MAX - 1) {
            printf("Temporary Stack Overflow while checking palindrome!\n");
            return;
        }
        tempStack[++tempTop] = digit;
        temp /= 10;
    }
    while (tempTop != -1) {
        rev = rev * 10 + tempStack[tempTop--];
    }
    if (rev == num)
        printf("%d is a Palindrome \n", num);
    else
        printf("%d is NOT a Palindrome \n", num);
}
void overflowUnderflowDemo() {
    top = -1;
    printf("\nDemonstrating Overflow \n");
    for (int i = 1; i <= MAX + 1; i++) {
        if (top == MAX - 1)
            printf("Overflow occurs when trying to push %d\n", i);
        else {
            stack[++top] = i;
            printf("Pushed %d\n", stack[top]);
        }
    }
    printf("\n Demonstrating Underflow\n");
    for (int i = 1; i <= MAX + 1; i++) {
        if (top == -1)
            printf("Underflow occurs when trying to pop at step %d\n", i);
        else
            printf("Popped %d\n", stack[top--]);
    }
}
int main() {
    int choice, value;

    while (1) {
        printf("\n\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Palindrome Check\n");
        printf("4. Overflow/Underflow Demonstration\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                palindromeCheck();
                break;

            case 4:
                overflowUnderflowDemo();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program... Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
