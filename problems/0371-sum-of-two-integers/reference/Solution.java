class Solution {
    public int getSum(int a, int b) {
        int x = a;
        int y = b;
        while (y != 0) {
            int carry = (x & y) << 1;
            x ^= y;
            y = carry;
        }
        return x;
    }
}
