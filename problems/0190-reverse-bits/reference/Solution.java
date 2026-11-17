class Solution {
    public int reverseBits(int n) {
        int value = n;
        int answer = 0;
        for (int i = 0; i < 32; i++) {
            answer = (answer << 1) | (value & 1);
            value >>>= 1;
        }
        return answer;
    }
}
