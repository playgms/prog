#include <stdio.h>
#include <time.h> // Include the time library for clock functions

int choose(int n, int dist[10], int visited[10]) {
    int count = 0, v = -1, min = 999;
    while (count < n) {
        min = 999;
        for (int i = 0; i < n; i++) {
            if (dist[i] < min && visited[i] == 0) {
                min = dist[i];
                v = i;
            }
        }
        visited[v] = 1; // Mark vertex v as visited
        count++;
    }
    return v;
}

void dijkstras(int n, int dist[10], int visited[10], int cost[10][10]) {
    while (1) {
        int v = choose(n, dist, visited);
        if (v == -1) // All vertices have been visited
            break;

        for (int i = 0; i < n; i++) {
            if (dist[i] > dist[v] + cost[v][i])
                dist[i] = dist[v] + cost[v][i];
        }
    }
}

int main() {
    int startVertex, n, cost[10][10];
    int dist[10];
    int visited[10];
    double clk;
    clock_t starttime, endtime;

    printf("\nEnter number of vertices:");
    scanf("%d", &n);
    printf("\nEnter the cost of adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    
    printf("\nEnter the source vertex: ");
    scanf("%d", &startVertex);

    for (int i = 0; i < n; i++) {
        dist[i] = 999; // Initialize distances to infinity
        visited[i] = 0; // Mark all vertices as unvisited
    }
    
    dist[startVertex] = 0;

    starttime = clock();
    dijkstras(n, dist, visited, cost);
    endtime = clock();
    
    printf("\nShortest distances:\n");
    for (int i = 0; i < n; i++)
        printf("%d to %d = %d\n", startVertex, i, dist[i]);

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("The time taken is %f seconds\n", clk);

    return 0;
}
