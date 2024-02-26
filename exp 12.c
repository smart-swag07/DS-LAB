#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void display(int a[MAX]);
int create(int num);
void linearprob(int a[MAX], int key, int num);

void main() {
    int a[MAX], i, num, key, ans = 1;
    printf("Collision handling by linear probing\n");
    for (i = 0; i < MAX; i++)
        a[i] = -1;
    do {
        printf("Enter the data: ");
        scanf("%d", &num);
        key = create(num);
        linearprob(a, key, num);
        printf("Do you want to continue [1/0]: ");
        scanf("%d", &ans);
    } while (ans);
    display(a);
}

int create(int num) {
    int key;
    key = num % 100;
    return key;
}

void linearprob(int a[MAX], int key, int num) {
    int flag = 0, i;
    if (a[key] == -1)
        a[key] = num;
    else {
        printf("\nCollision occurred. Resolving...\n");
        i = key + 1;
        while (i != key) {
            if (i == MAX)
                i = 0;
            if (a[i] == -1) {
                a[i] = num;
                flag = 1;
                break;
            }
            i++;
        }
        if (flag == 0)
            printf("Hash table full. Unable to resolve collision.\n");
    }
}

void display(int a[MAX]) {
    int ch, i;
    printf("\n1. Display all\n2. Filtered display\n");
    printf("Enter choice: ");
    scanf("%d", &ch);
    if (ch == 1) {
        for (i = 0; i < MAX; i++)
            printf("%d\t%d\n", i, a[i]);
    } else {
        for (i = 0; i < MAX; i++) {
            if (a[i] != -1) {
                printf("%d\t%d\n", i, a[i]);
            }
        }
    }
}
