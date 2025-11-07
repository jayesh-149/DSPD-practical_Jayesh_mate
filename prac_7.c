#include <stdio.h>
#include <stdlib.h>

int graph[10][10], visited[10];
int queue[100], front = 0, rear = 0;
int stackArr[100], top = -1;

void breadthFirstSearch(int startNode, int totalNodes) {
    int i,current;
    for (i=1;i<=totalNodes;i++) visited[i] = 0;
    front = rear = 0;
    queue[rear++] = startNode;
    visited[startNode] = 1;
    printf("BFS: ");
    while (front < rear) {
        current = queue[front++];
        printf("%d ", current);
        for (i = 1; i <= totalNodes; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
void depthFirstSearch(int startNode, int totalNodes) {
    int i, current;
    for (i = 1; i <= totalNodes; i++) visited[i] = 0;
    top = -1;
    stackArr[++top] = startNode;
    printf("DFS: ");
    while (top != -1) {
        current = stackArr[top--];
        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;
            for (i = totalNodes; i >= 1; i--) {
                if (graph[current][i] && !visited[i]) stackArr[++top] = i;
            }
        }
    }
    printf("\n");
}
int main() {
    int totalNodes = 9;
    graph[1][2]=graph[2][1]=1; graph[1][4]=graph[4][1]=1;
    graph[2][3]=graph[3][2]=1; graph[2][5]=graph[5][2]=1;
    graph[3][6]=graph[6][3]=1; graph[4][5]=graph[5][4]=1;
    graph[4][7]=graph[7][4]=1; graph[5][6]=graph[6][5]=1;
    graph[5][8]=graph[8][5]=1; graph[6][9]=graph[9][6]=1;
    graph[7][8]=graph[8][7]=1; graph[8][9]=graph[9][8]=1;

    breadthFirstSearch(1, totalNodes);
    depthFirstSearch(1, totalNodes);
    return 0;
}
/*
1 — 2 — 3
|   |   |
4 — 5 — 6
|   |   |
7 — 8 — 9
*/