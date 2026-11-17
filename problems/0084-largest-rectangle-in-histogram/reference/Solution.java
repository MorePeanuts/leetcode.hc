class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int[] stack = new int[n + 1];
        int count = 0;
        int best = 0;
        for (int i = 0; i <= n; i++) {
            int height = i == n ? 0 : heights[i];
            while (count > 0 && heights[stack[count - 1]] >= height) {
                int top = stack[--count];
                int left = count > 0 ? stack[count - 1] + 1 : 0;
                int area = heights[top] * (i - left);
                if (area > best) best = area;
            }
            stack[count++] = i;
        }
        return best;
    }
}
