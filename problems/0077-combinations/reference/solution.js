function combine(n, k) {
    const result = [];
    const path = [];

    function visit(start, needed) {
        if (needed === 0) {
            result.push(path.slice());
            return;
        }
        for (let value = start; value <= n - needed + 1; value++) {
            path.push(value);
            visit(value + 1, needed - 1);
            path.pop();
        }
    }

    visit(1, k);
    return result;
}
