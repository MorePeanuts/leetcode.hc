class Solution {
    public boolean canReach(int[] arr, int start) {
        boolean[] seen = new boolean[arr.length];
        int[] stack = new int[arr.length];
        int size = 0;
        stack[size++] = start;
        seen[start] = true;
        while (size > 0) {
            int i = stack[--size];
            if (arr[i] == 0) return true;
            for (int j : new int[]{i - arr[i], i + arr[i]}) {
                if (j >= 0 && j < arr.length && !seen[j]) {
                    seen[j] = true;
                    stack[size++] = j;
                }
            }
        }
        return false;
    }
}
