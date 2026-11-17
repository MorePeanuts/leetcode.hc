class Solution {
public:
    int reverseBits(int n) {
        uint32_t value = static_cast<uint32_t>(n); // INPUTn;
        uint32_t answer = 0;
        for (int i = 0; i < 32; i++) {
            answer = (answer << 1) | (value & 1);
            value >>= 1;
        }
        return static_cast<int>(answer);
    }
};
