function largestRectangleArea(heights: number[]): number {
    let n = heights.length;
    const stack = new Int32Array(n + 1);
    let count = 0;
    let best = 0;
    for (let i = 0; i <= n; i++) {
        let height = i === n ? 0 : heights[i];
        while (count > 0 && heights[stack[count - 1]] >= height) {
            let top = stack[--count];
            let left = count > 0 ? stack[count - 1] + 1 : 0;
            let area = heights[top] * (i - left);
            if (area > best) best = area;
        }
        stack[count++] = i;
    }
    return best;
}
