typedef struct {
    char* email;
    int account;
} Entry;

static int byEmail(const void* left, const void* right) {
    const Entry* a = left;
    const Entry* b = right;
    return strcmp(a->email, b->email);
}

static int root(int* parent, int id) {
    while (parent[id] != id) {
        parent[id] = parent[parent[id]];
        id = parent[id];
    }
    return id;
}

char*** accountsMerge(char*** accounts, int accountsSize, int* accountsColSize,
                      int* returnSize, int** returnColumnSizes) {
    int total = 0;
    int* parent = malloc(accountsSize * sizeof(*parent));
    for (int i = 0; i < accountsSize; i++) {
        total += accountsColSize[i] - 1;
        parent[i] = i;
    }
    Entry* entries = malloc(total * sizeof(*entries));
    int count = 0;
    for (int i = 0; i < accountsSize; i++) {
        for (int j = 1; j < accountsColSize[i]; j++) {
            entries[count++] = (Entry){accounts[i][j], i};
        }
    }
    qsort(entries, total, sizeof(*entries), byEmail);
    for (int i = 1; i < total; i++) {
        if (strcmp(entries[i - 1].email, entries[i].email) == 0) {
            parent[root(parent, entries[i].account)] = root(parent, entries[i - 1].account);
        }
    }

    // Compact each equal-email run to one entry associated with its final root.
    int unique = 0;
    int* sizes = calloc(accountsSize, sizeof(*sizes));
    for (int i = 0; i < total; i++) {
        if (unique && strcmp(entries[unique - 1].email, entries[i].email) == 0) {
            continue;
        }
        int id = root(parent, entries[i].account);
        entries[unique++] = (Entry){entries[i].email, id};
        sizes[id]++;
    }

    char*** result = malloc(accountsSize * sizeof(*result));
    *returnColumnSizes = malloc(accountsSize * sizeof(int));
    *returnSize = 0;
    int* rowOf = malloc(accountsSize * sizeof(*rowOf));
    for (int i = 0; i < accountsSize; i++) {
        if (sizes[i] > 0) {
            int row = (*returnSize)++;
            rowOf[i] = row;
            result[row] = malloc((sizes[i] + 1) * sizeof(char*));
            result[row][0] = accounts[i][0];
            (*returnColumnSizes)[row] = 1;
        }
    }
    for (int i = 0; i < unique; i++) {
        int row = rowOf[entries[i].account];
        result[row][(*returnColumnSizes)[row]++] = entries[i].email;
    }
    free(parent);
    free(entries);
    free(sizes);
    free(rowOf);
    return result;
}
