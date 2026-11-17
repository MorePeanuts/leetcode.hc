#include <stdbool.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int n = graphSize;
    int color[100] = {0};
    int stack[100];
    for (int start = 0; start < n; start++) {
        if (color[start] != 0) continue;
        color[start] = 1;
        int count = 1;
        stack[0] = start;
        while (count > 0) {
            int node = stack[--count];
            for (int i = 0; i < graphColSize[node]; i++) {
                int neighbor = graph[node][i];
                if (color[neighbor] == color[node]) return false;
                if (color[neighbor] == 0) {
                    color[neighbor] = -color[node];
                    stack[count++] = neighbor;
                }
            }
        }
    }
    return true;
}
