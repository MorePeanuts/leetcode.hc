class Solution {
    using Entry = std::pair<double, int>;
    using Heap = std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>>;

public:
    int leastInterval(std::vector<char>& tasks, int n) {
        int length = static_cast<int>(tasks.size());
        std::vector<int> counts(26);
        std::vector<int> coolingCounts(length);
        std::vector<int> coolingUntil(length);
        for (int i = 0; i < length; ++i) {
            ++counts[tasks[i] - 'A'];
        }
        Heap queue;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0) {
                queue.emplace(-counts[i], counts[i]);
            }
        }
        int time = 0;
        int head = 0;
        int tail = 0;
        while (static_cast<int>(queue.size()) > 0 || head < tail) {
            ++time;
            if (static_cast<int>(queue.size()) > 0) {
                Entry entry = queue.top();
                queue.pop();
                int remaining = entry.second - 1;
                if (remaining > 0) {
                    coolingCounts[tail] = remaining;
                    coolingUntil[tail++] = time + n;
                }
            } else {
                time = coolingUntil[head];
            }
            if (head < tail && coolingUntil[head] == time) {
                int ready = coolingCounts[head++];
                queue.emplace(-ready, ready);
            }
        }




        return time;
    }
};
