#include <map>
#include <iterator>

class MyCalendar {
    std::map<int, int> events;

public:
    bool book(int startTime, int endTime) {
        auto next = events.lower_bound(startTime);
        if (next != events.end() && next->first < endTime) return false;
        if (next != events.begin() && std::prev(next)->second > startTime) return false;
        events.emplace_hint(next, startTime, endTime);
        return true;
    }
};
