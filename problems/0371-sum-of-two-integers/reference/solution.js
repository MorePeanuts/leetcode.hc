function getSum(a, b) {
    let x = a;
    let y = b;
    while (y !== 0) {
        let carry = (x & y) << 1;
        x ^= y;
        y = carry;
    }
    return x;
}
