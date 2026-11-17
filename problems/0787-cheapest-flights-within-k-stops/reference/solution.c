int findCheapestPrice(int n, int **flights, int edges, int *columnSizes, int src, int dst, int k) {
    (void)columnSizes;
    int first[n], second[n];
    int *distance = first;
    int *following = second;
    for (int i = 0; i < n; i++) {
        distance[i] = 1000000000;
    }
    distance[src] = 0;
    for (int round = 0; round <= k; round++) {
        memcpy(following, distance, n * sizeof(*distance));
        for (int i = 0; i < edges; i++) {
            int from = flights[i][0];
            int to = flights[i][1];
            int candidate = distance[from] + flights[i][2];
            if (candidate < following[to]) {
                following[to] = candidate;
            }
        }
        int *old = distance;
        distance = following;
        following = old;
    }
    return distance[dst] == 1000000000 ? -1 : distance[dst];
}
