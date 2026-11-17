#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        std::unordered_map<std::string, std::vector<std::string>> edges;
        for (const auto& ticket : tickets) edges[ticket[0]].push_back(ticket[1]);
        for (auto& [airport, destinations] : edges) {
            std::sort(destinations.rbegin(), destinations.rend());
        }
        std::vector<std::string> stack{"JFK"};
        std::vector<std::string> result;
        while (!stack.empty()) {
            auto& destinations = edges[stack.back()];
            if (destinations.empty()) {
                result.push_back(stack.back());
                stack.pop_back();
            } else {
                stack.push_back(destinations.back());
                destinations.pop_back();
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
