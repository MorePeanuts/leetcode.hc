int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int best = 0;
    while (left < right) {
        int low = height[left] < height[right] ? height[left] : height[right];
        int area = low * (right - left);
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
