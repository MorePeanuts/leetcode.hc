class Solution {
    using Entry = std::pair<double, int>;
    using Heap = std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>>;

public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        int rows = static_cast<int>(nums1.size());
        int cols = static_cast<int>(nums2.size());
        int seeds = rows < k ? rows : k;
        Heap queue;
        for (int i = 0; i < seeds; ++i) {
            queue.emplace(nums1[i] + nums2[0], i * cols);
        }
        std::vector<std::vector<int>> result;
        result.reserve(k);
        for (int count = 0; count < k; ++count) {
            Entry entry = queue.top();
            queue.pop();
            int id = entry.second;
            int i = id / cols;
            int j = id % cols;
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < cols) {
                queue.emplace(nums1[i] + nums2[j + 1], id + 1);
            }
        }

        return result;
    }
};
