function combinationSum3(k, n) {
    const result = [];
    const path = [];

    function visit(start, needed, remaining) {
        if (needed === 0) {
            if (remaining === 0) {
                result.push(path.slice());
            }
            return;
        }
        for (let value = start; value <= 9 - needed + 1 && value <= remaining; value++) {
            path.push(value);
            visit(value + 1, needed - 1, remaining - value);
            path.pop();
        }
    }

    visit(1, k, n);
    return result;
}
