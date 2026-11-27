int maximumDetonation(int** bombs, int bombsSize, int* bombsColSize) {
    int edges[100][100], degree[100] = {0};
    for (int i = 0; i < bombsSize; i++) {
        long long radius = bombs[i][2];
        for (int j = 0; j < bombsSize; j++) {
            long long dx = bombs[i][0] - bombs[j][0];
            long long dy = bombs[i][1] - bombs[j][1];
            if (i != j && dx * dx + dy * dy <= radius * radius) {
                edges[i][degree[i]++] = j;
            }
        }
    }

    int best = 0;
    for (int start = 0; start < bombsSize; start++) {
        bool seen[100] = {false};
        int queue[100], tail = 1;
        queue[0] = start;
        seen[start] = true;
        for (int head = 0; head < tail; head++) {
            int node = queue[head];
            for (int j = 0; j < degree[node]; j++) {
                int next = edges[node][j];
                if (!seen[next]) {
                    seen[next] = true;
                    queue[tail++] = next;
                }
            }
        }
        if (tail > best) best = tail;
        if (best == bombsSize) break;
    }
    return best;
}
