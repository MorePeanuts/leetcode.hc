typedef struct {
    struct TreeNode* node;
    int phase;
    int left;
} Frame;

int diameterOfBinaryTree(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    Frame* stack = malloc(10000 * sizeof(*stack));
    int size = 0;
    stack[size++] = (Frame){.node = root};
    int best = 0;
    int height = 0;
    while (size > 0) {
        Frame* frame = &stack[size - 1];
        if (frame->phase == 0) {
            frame->phase = 1;
            if (frame->node->left != NULL) {
                stack[size++] = (Frame){.node = frame->node->left};
                continue;
            }
            height = 0;
        }
        if (frame->phase == 1) {
            frame->left = height;
            frame->phase = 2;
            if (frame->node->right != NULL) {
                stack[size++] = (Frame){.node = frame->node->right};
                continue;
            }
            height = 0;
        }
        int through = frame->left + height;
        if (through > best) {
            best = through;
        }
        height = (frame->left > height ? frame->left : height) + 1;
        --size;
    }
    free(stack);
    return best;
}
