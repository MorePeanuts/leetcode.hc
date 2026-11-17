import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        Map<String, List<String>> edges = new HashMap<>();
        for (List<String> ticket : tickets)
            edges.computeIfAbsent(ticket.get(0), key -> new ArrayList<>()).add(ticket.get(1));
        for (List<String> destinations : edges.values()) destinations.sort(Collections.reverseOrder());
        ArrayDeque<String> stack = new ArrayDeque<>();
        ArrayList<String> result = new ArrayList<>();
        stack.push("JFK");
        while (!stack.isEmpty()) {
            List<String> destinations = edges.get(stack.peek());
            if (destinations == null || destinations.isEmpty()) {
                result.add(stack.pop());
            } else {
                stack.push(destinations.remove(destinations.size() - 1));
            }
        }
        Collections.reverse(result);
        return result;
    }
}
