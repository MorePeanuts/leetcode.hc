enum { MAX_VARIABLES = 40 };  // Each of the 20 equations has two endpoints.

static int lookup(char** names, int count, const char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

static int intern(char** names, int* count, char* name) {
    int id = lookup(names, *count, name);
    if (id < 0) {
        id = *count;
        names[(*count)++] = name;
    }
    return id;
}

double* calcEquation(char*** equations, int equationsSize, int* equationsColSize,
                     double* values, int valuesSize, char*** queries, int queriesSize,
                     int* queriesColSize, int* returnSize) {
    char* names[MAX_VARIABLES];
    double edge[MAX_VARIABLES][MAX_VARIABLES] = {0};
    int count = 0;
    for (int i = 0; i < equationsSize; i++) {
        int a = intern(names, &count, equations[i][0]);
        int b = intern(names, &count, equations[i][1]);
        edge[a][b] = values[i];
        edge[b][a] = 1.0 / values[i];
    }

    double* result = malloc(queriesSize * sizeof(*result));
    *returnSize = queriesSize;
    for (int i = 0; i < queriesSize; i++) {
        int start = lookup(names, count, queries[i][0]);
        int target = lookup(names, count, queries[i][1]);
        result[i] = -1.0;
        if (start < 0 || target < 0) {
            continue;
        }
        int queue[MAX_VARIABLES], tail = 0;
        bool seen[MAX_VARIABLES] = {false};
        double product[MAX_VARIABLES];
        queue[tail++] = start;
        seen[start] = true;
        product[start] = 1.0;
        for (int head = 0; head < tail; head++) {
            int node = queue[head];
            if (node == target) {
                result[i] = product[node];
                break;
            }
            for (int next = 0; next < count; next++) {
                if (edge[node][next] > 0 && !seen[next]) {
                    seen[next] = true;
                    product[next] = product[node] * edge[node][next];
                    queue[tail++] = next;
                }
            }
        }
    }
    return result;
}
