#include <algorithm>
#include <queue>
#include <vector>

class Solution {
    struct Entry {
        int value;
        int row;
        int column;

        bool operator<(const Entry& other) const { return value > other.value; }
    };

public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int n = static_cast<int>(matrix.size());
        std::priority_queue<Entry> heap;
        for (int row = 0; row < std::min(n, k); row++)
            heap.push({matrix[row][0], row, 0});
        for (int i = 1; i < k; i++) {
            Entry root = heap.top();
            heap.pop();
            int column = root.column + 1;
            if (column < n) heap.push({matrix[root.row][column], root.row, column});
        }
        return heap.top().value;
    }
};
