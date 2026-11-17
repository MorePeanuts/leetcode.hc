function isHappy(n: number): boolean {
    function step(value: number): number {
        let sum = 0;
        while (value !== 0) {
            const digit = value % 10;
            sum += digit * digit;
            value = Math.trunc(value / 10);
        }
        return sum;
    }

    let slow = n;
    let fast = step(n);
    while (fast !== 1 && slow !== fast) {
        slow = step(slow);
        fast = step(step(fast));
    }
    return fast === 1;
}
