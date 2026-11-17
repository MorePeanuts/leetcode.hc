class TimeMap {
    using Entry = std::pair<int, std::string>;
    std::unordered_map<std::string, std::vector<Entry>> histories;

public:
    void set(std::string key, std::string value, int timestamp) {
        histories[std::move(key)].emplace_back(timestamp, std::move(value));
    }

    std::string get(std::string key, int timestamp) {
        auto found = histories.find(key);
        if (found == histories.end()) {
            return "";
        }
        const auto& history = found->second;
        auto after = std::upper_bound(history.begin(), history.end(), timestamp,
            [](int time, const Entry& entry) { return time < entry.first; });
        return after == history.begin() ? "" : std::prev(after)->second;
    }
};
