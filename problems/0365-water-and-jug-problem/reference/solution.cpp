class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        return target <= x + y && target % std::gcd(x, y) == 0;
    }
};
