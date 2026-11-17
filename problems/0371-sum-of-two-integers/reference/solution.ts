function getSum(a: number, b: number): number {
    let x = a;
    let y = b;
    while (y !== 0) {
        let carry = (x & y) << 1;
        x ^= y;
        y = carry;
    }
    return x;
}
