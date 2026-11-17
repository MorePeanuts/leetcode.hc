import java.util.ArrayDeque;

class Solution {
    private static class Frame {
        final TreeNode node;
        int stage;
        int leftGain;

        Frame(TreeNode node) {
            this.node = node;
        }
    }

    public int maxPathSum(TreeNode root) {
        ArrayDeque<Frame> stack = new ArrayDeque<>();
        stack.push(new Frame(root));
        int best = root.val;
        int gain = 0;
        while (!stack.isEmpty()) {
            Frame frame = stack.peek();
            if (frame.stage == 0) {
                frame.stage = 1;
                if (frame.node.left != null) {
                    stack.push(new Frame(frame.node.left));
                    continue;
                }
                gain = 0;
            }
            if (frame.stage == 1) {
                frame.leftGain = gain > 0 ? gain : 0;
                frame.stage = 2;
                if (frame.node.right != null) {
                    stack.push(new Frame(frame.node.right));
                    continue;
                }
                gain = 0;
            }
            int rightGain = gain > 0 ? gain : 0;
            int through = frame.node.val + frame.leftGain + rightGain;
            if (through > best) {
                best = through;
            }
            gain = frame.node.val + (frame.leftGain > rightGain ? frame.leftGain : rightGain);
            stack.pop();
        }

        return best;
    }
}
