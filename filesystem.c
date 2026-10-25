#include <stdio.h>
#include <string.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
char names[MAX][30];
int n;

void BFS(int start, char target[])
{
    int queue[MAX], front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int v = queue[front++];
        printf("%s ", names[v]);

        if (strcmp(names[v], target) == 0)
            found = 1;

        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    if (found)
        printf("\nFile found using BFS.\n");
    else
        printf("\nFile not found using BFS.\n");
}

void DFS(int v, char target[], int *found)
{
    visited[v] = 1;
    printf("%s ", names[v]);

    if (strcmp(names[v], target) == 0)
        *found = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
            DFS(i, target, found);
    }
}

int main()
{
    int edges, u, v, start;
    char target[30];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter file/directory names:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Node %d: ", i);
        scanf("%29s", names[i]);
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > n * (n - 1) / 2)
    {
        printf("Invalid number of edges.\n");
        return 1;
    }

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (two node numbers): ");
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            printf("Invalid node number.\n");
            return 1;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting node number: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting node.\n");
        return 1;
    }

    printf("Enter file to search: ");
    scanf("%29s", target);

    BFS(start, target);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int found = 0;

    printf("\nDFS Traversal: ");
    DFS(start, target, &found);

    if (found)
        printf("\nFile found using DFS.\n");
    else
        printf("\nFile not found using DFS.\n");

    return 0;
}
