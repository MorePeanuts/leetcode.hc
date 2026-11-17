import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) {
            return false;
        }
        Map<Integer, Integer> counts = new HashMap<>();
        for (int value : hand) {
            counts.merge(value, 1, Integer::sum);
        }
        Arrays.sort(hand);
        for (int first : hand) {
            int amount = counts.get(first);
            if (amount == 0) {
                continue;
            }
            for (int value = first; value < first + groupSize; value++) {
                int available = counts.getOrDefault(value, 0);
                if (available < amount) {
                    return false;
                }
                counts.put(value, available - amount);
            }
        }
        return true;
    }
}
