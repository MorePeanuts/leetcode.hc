function fib(n) {
    let current = 0, following = 1;
    for (let i = 0; i < n; i++) {
        const sum = current + following;
        current = following;
        following = sum;
    }
    return current;
}
