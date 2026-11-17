import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    private record Entry(double priority, int value) {}

    public int leastInterval(char[] tasks, int n) {
        int length = tasks.length;
        int[] counts = new int[26];
        int[] coolingCounts = new int[length];
        int[] coolingUntil = new int[length];
        for (int i = 0; i < length; ++i) {
            ++counts[tasks[i] - 'A'];
        }
        PriorityQueue<Entry> queue = new PriorityQueue<>(Comparator.comparingDouble(Entry::priority));
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0) {
                queue.add(new Entry(-counts[i], counts[i]));
            }
        }
        int time = 0;
        int head = 0;
        int tail = 0;
        while (queue.size() > 0 || head < tail) {
            ++time;
            if (queue.size() > 0) {
                Entry entry = queue.remove();
                int remaining = entry.value() - 1;
                if (remaining > 0) {
                    coolingCounts[tail] = remaining;
                    coolingUntil[tail++] = time + n;
                }
            } else {
                time = coolingUntil[head];
            }
            if (head < tail && coolingUntil[head] == time) {
                int ready = coolingCounts[head++];
                queue.add(new Entry(-ready, ready));
            }
        }




        return time;
    }
}
