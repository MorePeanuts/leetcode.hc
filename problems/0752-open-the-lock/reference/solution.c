int openLock(char** deadends, int deadendsSize, char* target) {
    bool seen[10000] = {false};
    for (int i = 0; i < deadendsSize; i++) seen[atoi(deadends[i])] = true;
    if (seen[0]) return -1;
    int goal = atoi(target);
    int queue[10000] = {0};
    seen[0] = true;
    int head = 0, tail = 1;
    for (int turns = 0; head < tail; turns++) {
        int end = tail;
        while (head < end) {
            int state = queue[head++];
            if (state == goal) return turns;
            for (int place = 1; place <= 1000; place *= 10) {
                int digit = state / place % 10;
                int neighbors[2] = {
                    state + (digit == 9 ? -9 : 1) * place,
                    state + (digit == 0 ? 9 : -1) * place
                };
                for (int i = 0; i < 2; i++) {
                    int next = neighbors[i];
                    if (!seen[next]) {
                        seen[next] = true;
                        queue[tail++] = next;
                    }
                }
            }
        }
    }
    return -1;
}
