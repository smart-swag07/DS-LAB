#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int stack[MAX], top = -1, item;

void push();
void pop();
void palindrome();
void display();

void main() {
    int choice;
    while (1) {
        printf("------- STACK OPERATIONS -----\n");
        printf("1. push\n2. pop\n3. palindrome\n4. display\n5. exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                palindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

void push() {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else {
        printf("Enter the item to be pushed: ");
        scanf("%d", &item);
        top = top + 1;
        stack[top] = item;
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else {
        item = stack[top];
        top = top - 1;
        printf("Deleted item is %d\n", item);
    }
}

void display() {
    int i;
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

void palindrome() {
    int num[MAX], i = 0, k, flag = 1;
    k = top;
    while (k != -1)
        num[i++] = stack[k--];
    for (i = 0; i <= top; i++) {
        if (num[i] == stack[i])
            continue;
        else
            flag = 0;
    }
    if (top == -1)
        printf("Stack is empty\n");
    else {
        if (flag)
            printf("Palindrome\n");
        else
            printf("Not a palindrome\n");
    }
}

