int minMutation(char* startGene, char* endGene, char** bank, int bankSize) {
    char* queue[11] = {startGene};
    bool seen[10] = {false};
    int head = 0, tail = 1;
    for (int steps = 0; head < tail; steps++) {
        int end = tail;
        while (head < end) {
            const char* current = queue[head++];
            if (strcmp(current, endGene) == 0) return steps;
            for (int i = 0; i < bankSize; i++) {
                if (seen[i]) continue;
                int differences = 0;
                for (int j = 0; j < 8; j++) {
                    if (current[j] != bank[i][j]) differences++;
                }
                if (differences == 1) {
                    seen[i] = true;
                    queue[tail++] = bank[i];
                }
            }
        }
    }
    return -1;
}
