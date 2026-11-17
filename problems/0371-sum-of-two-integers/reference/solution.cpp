class Solution {
public:
    int getSum(int a, int b) {
        uint32_t x = static_cast<uint32_t>(a);
        uint32_t y = static_cast<uint32_t>(b);
        while (y != 0) {
            uint32_t carry = (x & y) << 1;
            x ^= y;
            y = carry;
        }
        return static_cast<int>(x);
    }
};
