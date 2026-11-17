function removeKdigits(num, k) {
    const digits = [];
    let len = 0;
    let n = num.length;
    for (let i = 0; i < n; ++i) {
        while (k > 0 && len > 0 && digits[len - 1] > num[i]) {
            --len;
            --k;
        }
        digits[len++] = num[i];
    }
    len -= k;
    let start = 0;
    while (start < len && digits[start] === "0") {
        ++start;
    }
    return start === len ? "0" : digits.slice(start, len).join("");
}
