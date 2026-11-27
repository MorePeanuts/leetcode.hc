class Solution {
    public int openLock(String[] deadends, String target) {
        boolean[] seen = new boolean[10000];
        for (String dead : deadends) seen[Integer.parseInt(dead)] = true;
        if (seen[0]) return -1;
        int goal = Integer.parseInt(target);
        int[] queue = new int[10000];
        seen[0] = true;
        int head = 0, tail = 1;
        for (int turns = 0; head < tail; turns++) {
            int end = tail;
            while (head < end) {
                int state = queue[head++];
                if (state == goal) return turns;
                for (int place = 1; place <= 1000; place *= 10) {
                    int digit = state / place % 10;
                    int up = state + (digit == 9 ? -9 : 1) * place;
                    int down = state + (digit == 0 ? 9 : -1) * place;
                    if (!seen[up]) {
                        seen[up] = true;
                        queue[tail++] = up;
                    }
                    if (!seen[down]) {
                        seen[down] = true;
                        queue[tail++] = down;
                    }
                }
            }
        }
        return -1;
    }
}
