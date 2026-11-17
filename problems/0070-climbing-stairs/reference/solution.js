function climbStairs(n) {
    let previous = 1;
    let current = 1;
    for (let i = 1; i < n; i++) {
        let next = current + previous;
        previous = current;
        current = next;
    }
    return current;
}
