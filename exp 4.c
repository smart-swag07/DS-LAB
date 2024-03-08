#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char s[SIZE];
int top = -1;

void push(char elem) {
    s[++top] = elem;
}

char pop() {
    return s[top--];
}

int pr(char elem) {
    switch (elem) {
        case '#':
            return 0;
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
            return 4;
        default:
            return -1; // Added a default case to handle unrecognized characters
    }
}

void main() {
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;
    printf("Enter the infix expression:\n");
    gets(infix);
    push('#');
    while ((ch = infix[i++]) != '\0') {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')') {
            while (s[top] != '(')
                postfix[k++] = pop();
            elem = pop(); // Discarding the '('
        } else {
            while (pr(s[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("Infix expression is: %s\nPostfix expression is: %s\n", infix, postfix);
}
