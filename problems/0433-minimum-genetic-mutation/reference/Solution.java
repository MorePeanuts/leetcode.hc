import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        ArrayDeque<String> queue = new ArrayDeque<>();
        Set<String> seen = new HashSet<>();
        queue.add(startGene);
        seen.add(startGene);
        for (int steps = 0; !queue.isEmpty(); steps++) {
            for (int count = queue.size(); count > 0; count--) {
                String current = queue.remove();
                if (current.equals(endGene)) return steps;
                for (String next : bank) {
                    if (seen.contains(next)) continue;
                    int differences = 0;
                    for (int i = 0; i < 8; i++) {
                        if (current.charAt(i) != next.charAt(i)) differences++;
                    }
                    if (differences == 1) {
                        seen.add(next);
                        queue.add(next);
                    }
                }
            }
        }
        return -1;
    }
}
