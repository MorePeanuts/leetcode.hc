#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int best[1000];
    bool used[1000] = {0};
    for (int i = 1; i < n; i++) best[i] = INT_MAX;
    best[0] = 0;
    int total = 0;
    for (int count = 0; count < n; count++) {
        int vertex = -1;
        for (int i = 0; i < n; i++) {
            if (!used[i] && (vertex < 0 || best[i] < best[vertex])) vertex = i;
        }
        used[vertex] = true;
        total += best[vertex];
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            int distance = abs(points[vertex][0] - points[i][0]) + abs(points[vertex][1] - points[i][1]);
            if (distance < best[i]) best[i] = distance;
        }
    }
    return total;
}
