#include <stdio.h>
#include <stdlib.h>

#define MAX 5

char q[MAX], item;
int f = 0, r = -1, count = 0;

void insert();
void delete();
void display();

int main() {
    int ch;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                getchar(); // Consume newline character left in the input buffer
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}

void insert() {
    if (count == MAX)
        printf("Queue overflow\n");
    else {
        printf("Enter the item to be inserted: ");
        scanf(" %c", &item); // Added space before %c to skip leading whitespace
        r = (r + 1) % MAX;
        q[r] = item;
        count++;
    }
}

void delete() {
    if (count == 0)
        printf("Queue underflow\n");
    else {
        printf("Deleted item is %c\n", q[f]);
        f = (f + 1) % MAX;
        count--;
    }
}

void display() {
    int j = f, i;
    if (count == 0)
        printf("Queue is empty\n");
    else {
        printf("Contents of circular queue:\n");
        for (i = 1; i <= count; i++) {
            printf("%c\t", q[j]);
            j = (j + 1) % MAX;
        }
        printf("\nTotal number of items = %d\n", count);
    }
}
