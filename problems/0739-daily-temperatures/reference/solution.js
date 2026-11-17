function dailyTemperatures(temperatures) {
    const n = temperatures.length;
    const result = Array(n);
    const stack = new Int32Array(n);
    let size = 0;
    for (let i = n - 1; i >= 0; i--) {
        while (size > 0 && temperatures[stack[size - 1]] <= temperatures[i]) {
            size--;
        }
        result[i] = size === 0 ? 0 : stack[size - 1] - i;
        stack[size++] = i;
    }
    return result;
}
