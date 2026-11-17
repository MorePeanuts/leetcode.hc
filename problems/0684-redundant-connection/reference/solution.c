#include <stdlib.h>

static int find(int* parent, int node) {
    while (parent[node] != node) {
        parent[node] = parent[parent[node]];
        node = parent[node];
    }
    return node;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int parent[1001], size[1001]; // n <= 1000
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < edgesSize; i++) {
        int a = find(parent, edges[i][0]);
        int b = find(parent, edges[i][1]);
        if (a == b) {
            int* result = malloc(2 * sizeof(*result));
            result[0] = edges[i][0];
            result[1] = edges[i][1];
            *returnSize = 2;
            return result;
        }
        if (size[a] < size[b]) {
            int old = a;
            a = b;
            b = old;
        }
        parent[b] = a;
        size[a] += size[b];
    }
    *returnSize = 0;
    return NULL;
}
