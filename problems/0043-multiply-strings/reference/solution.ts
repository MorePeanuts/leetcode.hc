function multiply(num1: string, num2: string): string {
    let m = num1.length;
    let n = num2.length;
    const digits = new Int32Array(m + n);
    for (let i = m - 1; i >= 0; --i) {
        for (let j = n - 1; j >= 0; --j) {
            let place = i + j + 1;
            let total = digits[place] + (num1.charCodeAt(i) - 48) * (num2.charCodeAt(j) - 48);
            digits[place] = total % 10;
            digits[place - 1] += Math.floor(total / 10);
        }
    }
    let start = 0;
    while (start + 1 < m + n && digits[start] === 0) {
        ++start;
    }
    return digits.subarray(start).join("");
}
