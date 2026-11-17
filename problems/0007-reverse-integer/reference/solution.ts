function reverse(x: number): number {
    const negative = x < 0;
    let remaining = negative ? x : -x;
    let answer = 0;
    const lastDigit = negative ? -8 : -7;
    while (remaining !== 0) {
        const digit = remaining % 10;
        if (answer < -214748364 || (answer === -214748364 && digit < lastDigit))
            return 0;
        answer = answer * 10 + digit;
        remaining = Math.trunc(remaining / 10);
    }
    return negative ? answer : -answer;
}
