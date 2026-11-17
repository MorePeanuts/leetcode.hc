function trap(height) {
    const n = height.length;
    let left = 0;
    let right = n - 1;
    let leftMax = 0;
    let rightMax = 0;
    let water = 0;
    while (left < right) {
        if (height[left] <= height[right]) {
            let h = height[left++];
            if (h > leftMax) {
                leftMax = h;
            }
            water += leftMax - h;
        } else {
            let h = height[right--];
            if (h > rightMax) {
                rightMax = h;
            }
            water += rightMax - h;
        }
    }
    return water;
}
