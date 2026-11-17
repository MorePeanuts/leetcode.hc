typedef struct {
    struct TreeNode* node;
    struct TreeNode* parent;
    bool ancestor;
    UT_hash_handle hh;
} Parent;

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // LeetCode bounds the tree at 100,000 nodes.
    Parent* entries = malloc(100000 * sizeof(*entries));
    struct TreeNode** stack = malloc(100000 * sizeof(*stack));
    Parent* parents = NULL;
    entries[0] = (Parent){.node = root};
    Parent* rootEntry = &entries[0];
    HASH_ADD_PTR(parents, node, rootEntry);
    stack[0] = root;
    int size = 1;
    int used = 1;
    while (size > 0) {
        struct TreeNode* node = stack[--size];
        struct TreeNode* children[] = {node->left, node->right};
        for (int i = 0; i < 2; ++i) {
            if (children[i] != NULL) {
                Parent* entry = &entries[used++];
                *entry = (Parent){.node = children[i], .parent = node};
                HASH_ADD_PTR(parents, node, entry);
                stack[size++] = children[i];
            }
        }
    }

    while (p != NULL) {
        Parent* entry;
        HASH_FIND_PTR(parents, &p, entry);
        entry->ancestor = true;
        p = entry->parent;
    }
    for (;;) {
        Parent* entry;
        HASH_FIND_PTR(parents, &q, entry);
        if (entry->ancestor) {
            break;
        }
        q = entry->parent;
    }
    HASH_CLEAR(hh, parents);
    free(entries);
    free(stack);
    return q;
}
