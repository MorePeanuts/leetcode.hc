class RecentCounter {
    deque<int> times;

public:
    int ping(int t) {
        times.push_back(t);
        while (times.front() < t - 3000) {
            times.pop_front();
        }
        return times.size();
    }
};
