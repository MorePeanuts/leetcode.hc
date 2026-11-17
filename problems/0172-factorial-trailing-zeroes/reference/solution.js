function trailingZeroes(n) {
    let total = 0;
    while (n > 0) {
        n = Math.floor(n / 5);
        total += n;
    }
    return total;
}
