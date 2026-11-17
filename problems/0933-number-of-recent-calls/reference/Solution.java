import java.util.ArrayDeque;
import java.util.Deque;

class RecentCounter {
    private final Deque<Integer> times = new ArrayDeque<>();

    public int ping(int t) {
        times.addLast(t);
        while (times.peekFirst() < t - 3000) {
            times.removeFirst();
        }
        return times.size();
    }
}
