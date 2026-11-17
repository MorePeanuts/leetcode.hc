#include <random>

class RandomizedSet {
    vector<int> values;
    unordered_map<int, size_t> positions;
    std::mt19937 random{std::random_device{}()};

public:
    bool insert(int val) {
        if (!positions.emplace(val, values.size()).second) {
            return false;
        }
        values.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = positions.find(val);
        if (it == positions.end()) {
            return false;
        }
        size_t index = it->second;
        int last = values.back();
        values[index] = last;
        positions[last] = index;
        values.pop_back();
        positions.erase(it);
        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<size_t> sample(0, values.size() - 1);
        return values[sample(random)];
    }
};
