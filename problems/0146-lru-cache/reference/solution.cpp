#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
    int capacity;
    std::list<std::pair<int, int>> order;
    std::unordered_map<int, decltype(order)::iterator> entries;

public:
    explicit LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto entry = entries.find(key);
        if (entry == entries.end()) return -1;
        order.splice(order.end(), order, entry->second);
        return entry->second->second;
    }

    void put(int key, int value) {
        auto entry = entries.find(key);
        if (entry != entries.end()) {
            entry->second->second = value;
            order.splice(order.end(), order, entry->second);
            return;
        }
        if (entries.size() == static_cast<size_t>(capacity)) {
            entries.erase(order.front().first);
            order.pop_front();
        }
        order.emplace_back(key, value);
        entries.emplace(key, std::prev(order.end()));
    }
};
