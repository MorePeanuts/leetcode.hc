class Solution {
    struct Frame {
        TreeNode *node;
        int stage;
        int leftGain;
    };

public:
    int maxPathSum(TreeNode *root) {
        vector<Frame> stack{{root, 0, 0}};
        int best = root->val;
        int gain = 0;
        while (!stack.empty()) {
            Frame &frame = stack.back();
            if (frame.stage == 0) {
                frame.stage = 1;
                if (frame.node->left != nullptr) {
                    stack.push_back({frame.node->left, 0, 0});
                    continue;
                }
                gain = 0;
            }
            if (frame.stage == 1) {
                frame.leftGain = gain > 0 ? gain : 0;
                frame.stage = 2;
                if (frame.node->right != nullptr) {
                    stack.push_back({frame.node->right, 0, 0});
                    continue;
                }
                gain = 0;
            }
            int rightGain = gain > 0 ? gain : 0;
            int through = frame.node->val + frame.leftGain + rightGain;
            if (through > best) {
                best = through;
            }
            gain = frame.node->val + (frame.leftGain > rightGain ? frame.leftGain : rightGain);
            stack.pop_back();
        }

        return best;
    }
};
