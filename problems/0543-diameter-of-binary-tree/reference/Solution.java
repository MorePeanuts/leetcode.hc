import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    private static class Frame {
        final TreeNode node;
        int phase;
        int left;

        Frame(TreeNode node) {
            this.node = node;
        }
    }

    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Deque<Frame> stack = new ArrayDeque<>();
        stack.push(new Frame(root));
        int best = 0;
        int height = 0;
        while (!stack.isEmpty()) {
            Frame frame = stack.peek();
            if (frame.phase == 0) {
                frame.phase = 1;
                if (frame.node.left != null) {
                    stack.push(new Frame(frame.node.left));
                    continue;
                }
                height = 0;
            }
            if (frame.phase == 1) {
                frame.left = height;
                frame.phase = 2;
                if (frame.node.right != null) {
                    stack.push(new Frame(frame.node.right));
                    continue;
                }
                height = 0;
            }
            int through = frame.left + height;
            if (through > best) {
                best = through;
            }
            height = (frame.left > height ? frame.left : height) + 1;
            stack.pop();
        }

        return best;
    }
}
