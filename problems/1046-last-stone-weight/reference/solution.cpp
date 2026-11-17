class Solution {
    static void siftDown(vector<int>& stones, int root, int n) {
        int value = stones[root];
        for (int child = 2 * root + 1; child < n; child = 2 * root + 1) {
            if (child + 1 < n && stones[child] < stones[child + 1]) child++;
            if (stones[child] <= value) break;
            stones[root] = stones[child];
            root = child;
        }
        stones[root] = value;
    }

public:
    int lastStoneWeight(vector<int>& stones) {
        int n = static_cast<int>(stones.size());
        for (int root = n / 2 - 1; root >= 0; root--) siftDown(stones, root, n);

        while (n > 1) {
            int first = stones[0];
            stones[0] = stones[--n];
            siftDown(stones, 0, n);
            int second = stones[0];
            if (first == second) {
                stones[0] = stones[--n];
            } else {
                stones[0] = first - second;
            }
            if (n > 0) siftDown(stones, 0, n);
        }
        return n > 0 ? stones[0] : 0;
    }
};
