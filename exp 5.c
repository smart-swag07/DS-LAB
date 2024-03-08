#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 50

char post[MAX];
int stack[MAX], top = -1, i;

void pushstack(int);
void calculator(char);

int main() {
    printf("Enter suffix expression: \n");
    gets(post);

    for (i = 0; i < strlen(post); i++) {
        if (post[i] >= '0' && post[i] <= '9')
            pushstack(i);
        else
            calculator(post[i]);
    }

    printf("Result = %d\n", stack[top]);
    return 0;
}

void pushstack(int i) {
    top = top + 1;
    stack[top] = (int) (post[i] - '0');
}

void calculator(char c) {
    int a, b, ans;
    b = stack[top--];
    a = stack[top--];

    switch (c) {
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        case '*':
            ans = a * b;
            break;
        case '/':
            ans = a / b;
            break;
        case '%':
            ans = a % b;
            break;
        case '^':
            ans = (int)pow(a, b);
            break;
        default:
            printf("Wrong input\n");
            exit(0);
    }

    top++;
    stack[top] = ans;
}



b.

#include <stdio.h>

void tower(int n, char frompeg, char topeg, char auxpeg);

int main() {
    int n;
    printf("Enter the number of discs: \n");
    scanf("%d", &n);
    printf("The number of moves in the Tower of Hanoi problem:\n");
    tower(n, 'A', 'C', 'B');
    return 0;
}

void tower(int n, char frompeg, char topeg, char auxpeg) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", frompeg, topeg);
        return;
    }
    tower(n - 1, frompeg, auxpeg, topeg);
    printf("Move disk %d from %c to %c\n", n, frompeg, topeg);
    tower(n - 1, auxpeg, topeg, frompeg);
}
