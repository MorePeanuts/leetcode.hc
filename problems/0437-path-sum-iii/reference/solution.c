typedef struct {
    long long sum;
    int count;
    UT_hash_handle hh;
} Prefix;

static int visit(struct TreeNode* node, long long sum, int target, Prefix** prefixes) {
    if (node == NULL) {
        return 0;
    }
    sum += node->val;
    long long needed = sum - target;
    Prefix* previous;
    HASH_FIND(hh, *prefixes, &needed, sizeof(needed), previous);
    int count = previous == NULL ? 0 : previous->count;

    Prefix* current;
    Prefix added = {.sum = sum};
    HASH_FIND(hh, *prefixes, &sum, sizeof(sum), current);
    bool inserted = current == NULL;
    if (inserted) {
        current = &added;
        HASH_ADD(hh, *prefixes, sum, sizeof(sum), current);
    }
    ++current->count;
    count += visit(node->left, sum, target, prefixes);
    count += visit(node->right, sum, target, prefixes);
    --current->count;
    if (inserted) {
        HASH_DEL(*prefixes, current);
    }
    return count;
}

int pathSum(struct TreeNode* root, int targetSum) {
    Prefix entry = {.sum = 0, .count = 1};
    Prefix* zero = &entry;
    Prefix* prefixes = NULL;
    HASH_ADD(hh, prefixes, sum, sizeof(entry.sum), zero);
    int result = visit(root, 0, targetSum, &prefixes);
    HASH_CLEAR(hh, prefixes);
    return result;
}
