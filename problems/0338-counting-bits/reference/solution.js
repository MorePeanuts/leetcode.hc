function countBits(n) {
    const result = [];
    result[0] = 0;
    for (let value = 1; value <= n; value++) {
        result[value] = result[value >> 1] + (value & 1);
    }
    return result;
}
