class Solution {
    public int fib(int n) {
        int current = 0, following = 1;
        for (int i = 0; i < n; i++) {
            int sum = current + following;
            current = following;
            following = sum;
        }
        return current;
    }
}
