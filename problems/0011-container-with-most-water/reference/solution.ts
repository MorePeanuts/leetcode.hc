function maxArea(height: number[]): number {
    let left = 0;
    let right = height.length - 1;
    let best = 0;
    while (left < right) {
        let low = height[left] < height[right] ? height[left] : height[right];
        let area = low * (right - left);
        if (area > best) {
            best = area;
        }
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }
    return best;
}
