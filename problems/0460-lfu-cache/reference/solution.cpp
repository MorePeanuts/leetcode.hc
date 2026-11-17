#include <list>
#include <unordered_map>

class LFUCache {
    struct Entry {
        int value;
        int count;
        std::list<int>::iterator position;
    };

    int capacity;
    int minimum = 0;
    std::unordered_map<int, Entry> entries;
    std::unordered_map<int, std::list<int>> groups;

    void touch(int key, Entry& entry) {
        int count = entry.count;
        auto group = groups.find(count);
        group->second.erase(entry.position);
        if (group->second.empty()) {
            groups.erase(group);
            if (count == minimum) minimum++;
        }
        auto& next = groups[++entry.count];
        next.push_back(key);
        entry.position = std::prev(next.end());
    }

public:
    explicit LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto found = entries.find(key);
        if (found == entries.end()) return -1;
        touch(key, found->second);
        return found->second.value;
    }

    void put(int key, int value) {
        auto found = entries.find(key);
        if (found != entries.end()) {
            found->second.value = value;
            touch(key, found->second);
            return;
        }
        if (entries.size() == static_cast<size_t>(capacity)) {
            auto group = groups.find(minimum);
            entries.erase(group->second.front());
            group->second.pop_front();
            if (group->second.empty()) groups.erase(group);
        }
        auto& first = groups[1];
        first.push_back(key);
        entries.emplace(key, Entry{value, 1, std::prev(first.end())});
        minimum = 1;
    }
};
