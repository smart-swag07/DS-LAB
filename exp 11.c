#include<stdio.h>
#include<stdlib.h>

int n, a[10][10], i, j, source, s[10], choice, count;

void bfs(int n, int a[10][10], int source, int s[]) {
    int q[10], u;
    int front = 1, rear = 1;
    s[source] = 1;
    q[rear] = source;
    while (front <= rear) {
        u = q[front];
        front = front + 1;
        for (i = 1; i <= n; i++)
            if (a[u][i] == 1 && s[i] == 0) {
                rear = rear + 1;
                q[rear] = i;
                s[i] = 1;
            }
    }
}

void dfs(int n, int a[10][10], int source, int s[]) {
    s[source] = 1;
    for (i = 1; i <= n; i++)
        if (a[source][i] == 1 && s[i] == 0)
            dfs(n, a, i, s);
}

int main() {
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    while (1) {
        printf("\n\n1. BFS\n2. DFS\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the source: ");
                scanf("%d", &source);
                for (i = 1; i <= n; i++)
                    s[i] = 0;
                bfs(n, a, source, s);
                for (i = 1; i <= n; i++) {
                    if (s[i] == 0)
                        printf("\nThe node %d is not reachable\n", i);
                    else
                        printf("\nThe node %d is reachable\n", i);
                }
                break;
            case 2:
                printf("\nEnter the source vertex: ");
                scanf("%d", &source);
                count = 0;
                for (i = 1; i <= n; i++)
                    s[i] = 0;
                dfs(n, a, source, s);
                for (i = 1; i <= n; i++)
                    if (s[i])
                        count = count + 1;
                if (count == n)
                    printf("\nThe graph is connected.");
                else
                    printf("\nThe graph is not connected.");
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}
