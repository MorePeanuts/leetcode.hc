class MedianFinder {
    using Entry = std::pair<double, int>;
    using Heap = std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>>;

    Heap low;
    Heap high;

public:
    void addNum(int num) {
        if (static_cast<int>(low.size()) > 0 && num > -low.top().first) {
            high.emplace(num, num);
        } else {
            low.emplace(-num, num);
        }
        if (static_cast<int>(low.size()) > static_cast<int>(high.size()) + 1) {
            Entry entry = low.top();
            low.pop();
            high.emplace(entry.second, entry.second);
        } else if (static_cast<int>(high.size()) > static_cast<int>(low.size())) {
            Entry entry = high.top();
            high.pop();
            low.emplace(-entry.second, entry.second);
        }
    }

    double findMedian() {
        if (static_cast<int>(low.size()) > static_cast<int>(high.size())) {
            return -low.top().first;
        }
        return (high.top().first - low.top().first) / 2;
    }
};
