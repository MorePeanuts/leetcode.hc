function combine(n: number, k: number): number[][] {
    const result: number[][] = [];
    const path: number[] = [];

    function visit(start: number, needed: number): void {
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
