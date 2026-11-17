#include <array>
#include <unordered_map>
#include <vector>

class DetectSquares {
    std::array<std::unordered_map<int, int>, 1001> columns;

    int frequency(int x, int y) const {
        if (x < 0 || x > 1000) return 0;
        auto entry = columns[x].find(y);
        return entry == columns[x].end() ? 0 : entry->second;
    }

public:
    void add(std::vector<int> point) {
        ++columns[point[0]][point[1]];
    }

    int count(std::vector<int> point) {
        int x = point[0], y = point[1];
        int result = 0;
        for (const auto [otherY, multiplicity] : columns[x]) {
            int side = otherY - y;
            if (side == 0) continue;
            result += multiplicity * (
                frequency(x - side, y) * frequency(x - side, otherY) +
                frequency(x + side, y) * frequency(x + side, otherY));
        }
        return result;
    }
};
