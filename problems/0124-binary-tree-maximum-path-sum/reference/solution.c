struct Frame {
    struct TreeNode *node;
    int stage;
    int leftGain;
};

int maxPathSum(struct TreeNode *root) {
    struct Frame *stack = malloc(30000 * sizeof(*stack));
    int size = 1;
    stack[0] = (struct Frame){.node = root};
    int best = root->val;
    int gain = 0;
    while (size > 0) {
        struct Frame *frame = &stack[size - 1];
        if (frame->stage == 0) {
            frame->stage = 1;
            if (frame->node->left != NULL) {
                stack[size++] = (struct Frame){.node = frame->node->left};
                continue;
            }
            gain = 0;
        }
        if (frame->stage == 1) {
            frame->leftGain = gain > 0 ? gain : 0;
            frame->stage = 2;
            if (frame->node->right != NULL) {
                stack[size++] = (struct Frame){.node = frame->node->right};
                continue;
            }
            gain = 0;
        }
        int rightGain = gain > 0 ? gain : 0;
        int through = frame->node->val + frame->leftGain + rightGain;
        if (through > best) {
            best = through;
        }
        gain = frame->node->val + (frame->leftGain > rightGain ? frame->leftGain : rightGain);
        size--;
    }
    free(stack);
    return best;
}
