function subsetsWithDup(values: number[]): number[][] {
    values.sort((a, b) => a - b);
    const size = values.length;
    const result: number[][] = [];
    const path: number[] = [];
    function visit(start: number): void {
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
