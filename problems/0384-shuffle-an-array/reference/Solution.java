import java.util.Random;

class Solution {
    private final int[] original;
    private final Random random = new Random();

    public Solution(int[] nums) {
        original = nums.clone();
    }

    public int[] reset() {
        return original.clone();
    }

    public int[] shuffle() {
        int[] result = reset();
        for (int i = result.length - 1; i > 0; i--) {
            int j = random.nextInt(i + 1);
            int old = result[i];
            result[i] = result[j];
            result[j] = old;
        }
        return result;
    }
}
