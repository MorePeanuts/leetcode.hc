function combinationSum2(values, target) {
    values.sort((a, b) => a - b);
    const size = values.length;
    const result = [];
    const path = [];
    function visit(start, remaining) {
        if (remaining === 0) {
            result.push(path.slice());
            return;
        }
        for (let i = start; i < size; ++i) {
            let value = values[i];
            if (value > remaining) {
                break;
            }
            if (i > start && value === values[i - 1]) {
                continue;
            }
            path.push(value);
            visit(i + 1, remaining - value);
            path.pop();
        }
    }
    visit(0, target);
    return result;
}
