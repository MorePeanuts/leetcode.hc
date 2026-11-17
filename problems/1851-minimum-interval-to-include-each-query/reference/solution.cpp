#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
    std::vector<int> minInterval(std::vector<std::vector<int>>& intervals, std::vector<int>& queries) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::pair<int, int>> order;
        for (int i = 0; i < static_cast<int>(queries.size()); i++) order.emplace_back(queries[i], i);
        std::sort(order.begin(), order.end());
        using Entry = std::pair<int, int>;
        std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> heap;
        std::vector<int> answer(queries.size(), -1);
        size_t next = 0;
        for (const auto [query, index] : order) {
            while (next < intervals.size() && intervals[next][0] <= query) {
                const auto& interval = intervals[next++];
                heap.emplace(interval[1] - interval[0] + 1, interval[1]);
            }
            while (!heap.empty() && heap.top().second < query) heap.pop();
            if (!heap.empty()) answer[index] = heap.top().first;
        }
        return answer;
    }
};
