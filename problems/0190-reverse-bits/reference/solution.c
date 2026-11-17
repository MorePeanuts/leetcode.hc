int reverseBits(int n) {
    uint32_t value = (uint32_t)n;
    uint32_t answer = 0;
    for (int i = 0; i < 32; i++) {
        answer = (answer << 1) | (value & 1);
        value >>= 1;
    }
    return (int)answer;
}
