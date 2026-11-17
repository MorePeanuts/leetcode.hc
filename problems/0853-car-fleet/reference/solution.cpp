class Solution {
public:


    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;
        cars.reserve(position.size());
        for (size_t i = 0; i < position.size(); ++i) {
            cars.emplace_back(position[i], speed[i]);
        }
        std::sort(cars.rbegin(), cars.rend());
        int fleets = 0;
        double slowest = 0;
        for (int i = 0; i < static_cast<int>(position.size()); ++i) {
            double time = static_cast<double>(target - cars[i].first) / cars[i].second;
            if (time > slowest) {
                ++fleets;
                slowest = time;
            }
        }

        return fleets;
    }
};
