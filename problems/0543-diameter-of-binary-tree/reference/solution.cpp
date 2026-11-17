class Solution {
    struct Frame {
        TreeNode* node;
        int phase = 0;
        int left = 0;
    };

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        std::vector<Frame> stack;
        stack.push_back(Frame{root});
        int best = 0;
        int height = 0;
        while (!stack.empty()) {
            Frame& frame = stack.back();
            if (frame.phase == 0) {
                frame.phase = 1;
                if (frame.node->left != nullptr) {
                    stack.push_back(Frame{frame.node->left});
                    continue;
                }
                height = 0;
            }
            if (frame.phase == 1) {
                frame.left = height;
                frame.phase = 2;
                if (frame.node->right != nullptr) {
                    stack.push_back(Frame{frame.node->right});
                    continue;
                }
                height = 0;
            }
            int through = frame.left + height;
            if (through > best) {
                best = through;
            }
            height = (frame.left > height ? frame.left : height) + 1;
            stack.pop_back();
        }

        return best;
    }
};
