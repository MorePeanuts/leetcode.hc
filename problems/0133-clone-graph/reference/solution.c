static struct Node* copyNode(struct Node* original) {
    struct Node* copy = malloc(sizeof(*copy));
    copy->val = original->val;
    copy->numNeighbors = original->numNeighbors;
    copy->neighbors = malloc((size_t)copy->numNeighbors * sizeof(*copy->neighbors));
    return copy;
}

struct Node* cloneGraph(struct Node* node) {
    if (node == NULL) {
        return NULL;
    }
    // Node values are unique and lie in [1, 100].
    struct Node* copies[101] = {NULL};
    struct Node* queue[100];
    int tail = 0;
    queue[tail++] = node;
    copies[node->val] = copyNode(node);
    for (int head = 0; head < tail; ++head) {
        struct Node* current = queue[head];
        struct Node* copy = copies[current->val];
        for (int i = 0; i < current->numNeighbors; ++i) {
            struct Node* neighbor = current->neighbors[i];
            if (copies[neighbor->val] == NULL) {
                copies[neighbor->val] = copyNode(neighbor);
                queue[tail++] = neighbor;
            }
            copy->neighbors[i] = copies[neighbor->val];
        }
    }
    return copies[node->val];
}
