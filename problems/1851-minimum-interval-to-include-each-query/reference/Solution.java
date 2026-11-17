import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    private record Entry(int length, int end) {}

    public int[] minInterval(int[][] intervals, int[] queries) {
        Arrays.sort(intervals, Comparator.comparingInt(interval -> interval[0]));
        Integer[] order = new Integer[queries.length];
        for (int i = 0; i < order.length; i++) order[i] = i;
        Arrays.sort(order, Comparator.comparingInt(i -> queries[i]));
        PriorityQueue<Entry> heap = new PriorityQueue<>(Comparator.comparingInt(Entry::length));
        int[] answer = new int[queries.length];
        int next = 0;
        for (int index : order) {
            int query = queries[index];
            while (next < intervals.length && intervals[next][0] <= query) {
                int[] interval = intervals[next++];
                heap.add(new Entry(interval[1] - interval[0] + 1, interval[1]));
            }
            while (!heap.isEmpty() && heap.element().end() < query) heap.remove();
            answer[index] = heap.isEmpty() ? -1 : heap.element().length();
        }
        return answer;
    }
}
