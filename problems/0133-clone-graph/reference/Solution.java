import java.util.ArrayDeque;
import java.util.IdentityHashMap;
import java.util.Map;
import java.util.Queue;

class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) {
            return null;
        }
        Map<Node, Node> copies = new IdentityHashMap<>();
        copies.put(node, new Node(node.val));
        Queue<Node> queue = new ArrayDeque<>();
        queue.add(node);
        while (!queue.isEmpty()) {
            Node current = queue.remove();
            Node copy = copies.get(current);
            for (Node neighbor : current.neighbors) {
                if (!copies.containsKey(neighbor)) {
                    copies.put(neighbor, new Node(neighbor.val));
                    queue.add(neighbor);
                }
                copy.neighbors.add(copies.get(neighbor));
            }
        }
        return copies.get(node);
    }
}
