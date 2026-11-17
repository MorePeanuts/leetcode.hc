int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result = malloc(((size_t)digitsSize + 1) * sizeof(*result));
    int carry = 1;
    for (int i = digitsSize - 1; i >= 0; --i) {
        int value = digits[i] + carry;
        result[i + 1] = value % 10;
        carry = value / 10;
    }
    if (carry != 0) {
        result[0] = carry;
        *returnSize = digitsSize + 1;
    } else {
        memmove(result, result + 1, (size_t)digitsSize * sizeof(*result));
        *returnSize = digitsSize;
    }
    return result;
}
