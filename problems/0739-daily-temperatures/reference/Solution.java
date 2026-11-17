class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] result = new int[n];
        int[] stack = new int[n];
        int size = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (size > 0 && temperatures[stack[size - 1]] <= temperatures[i]) {
                size--;
            }
            result[i] = size == 0 ? 0 : stack[size - 1] - i;
            stack[size++] = i;
        }
        return result;
    }
}
