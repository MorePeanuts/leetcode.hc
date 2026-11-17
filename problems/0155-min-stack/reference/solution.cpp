#include <algorithm>
#include <utility>
#include <vector>

class MinStack {
    std::vector<std::pair<int, int>> entries;

public:
    void push(int value) {
        int minimum = entries.empty() ? value : std::min(value, entries.back().second);
        entries.emplace_back(value, minimum);
    }

    void pop() { entries.pop_back(); }
    int top() { return entries.back().first; }
    int getMin() { return entries.back().second; }
};
