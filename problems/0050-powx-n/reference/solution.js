function myPow(x, n) {
    let exponent = n;
    if (exponent < 0) {
        x = 1 / x;
        exponent = -exponent;
    }
    let result = 1;
    while (exponent > 0) {
        if (exponent % 2 !== 0) {
            result *= x;
        }
        x *= x;
        exponent = Math.floor(exponent / 2);
    }
    return result;
}
