class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;

public:
    KthLargest(int k, vector<int> &nums) : k(k) {
        for (int value : nums) {
            add(value);
        }
    }

    int add(int val) {
        if (heap.size() < static_cast<size_t>(k)) {
            heap.push(val);
        } else if (val > heap.top()) {
            heap.pop();
            heap.push(val);
        }
        return heap.top();
    }
};
