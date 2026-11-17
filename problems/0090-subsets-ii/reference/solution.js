function subsetsWithDup(values) {
    values.sort((a, b) => a - b);
    const size = values.length;
    const result = [];
    const path = [];
    function visit(start) {
        result.push(path.slice());
        for (let i = start; i < size; ++i) {
            let value = values[i];

            if (i > start && value === values[i - 1]) {
                continue;
            }
            path.push(value);
            visit(i + 1);
            path.pop();
        }
    }
    visit(0);
    return result;
}
