#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        std::unordered_map<std::string, std::vector<std::string>> buckets;
        for (auto word : wordList) {
            for (char& letter : word) {
                char old = letter;
                letter = '*';
                auto& bucket = buckets[word];
                letter = old;
                bucket.push_back(word);
            }
        }
        std::vector<std::string> queue{beginWord};
        std::unordered_set<std::string> seen{beginWord};
        int distance = 1;
        for (size_t head = 0; head < queue.size(); distance++) {
            const size_t end = queue.size();
            for (; head < end; head++) {
                auto word = queue[head];
                if (word == endWord) return distance;
                for (char& letter : word) {
                    char old = letter;
                    letter = '*';
                    auto entry = buckets.find(word);
                    letter = old;
                    if (entry == buckets.end()) continue;
                    for (const auto& next : entry->second)
                        if (seen.insert(next).second) queue.push_back(next);
                    buckets.erase(entry);
                }
            }
        }
        return 0;
    }
};
