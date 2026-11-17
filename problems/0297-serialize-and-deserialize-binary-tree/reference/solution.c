#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* serialize(struct TreeNode* root) {
    // Keep the missing children in level order as well.
    size_t capacity = 16;
    struct TreeNode** queue = malloc(capacity * sizeof(*queue));
    if (!queue) abort();
    size_t count = 1;
    queue[0] = root;
    for (size_t i = 0; i < count; ++i) {
        struct TreeNode* node = queue[i];
        if (!node) continue;
        if (count + 2 > capacity) {
            capacity *= 2;
            queue = realloc(queue, capacity * sizeof(*queue));
            if (!queue) abort();
        }
        queue[count++] = node->left;
        queue[count++] = node->right;
    }

    // Each token uses at most 11 decimal characters and one comma.
    char* data = malloc(12 * count + 1);
    if (!data) abort();
    char* next = data;
    for (size_t i = 0; i < count; ++i) {
        if (queue[i]) {
            next += sprintf(next, "%d,", queue[i]->val);
        } else {
            *next++ = '#';
            *next++ = ',';
        }
    }
    *next = '\0';
    free(queue);
    return data;
}

static struct TreeNode* read_node(const char** next) {
    if (**next == '#') {
        *next += 2;
        return NULL;
    }
    char* end;
    int value = (int)strtol(*next, &end, 10);
    *next = end + 1;

    struct TreeNode* node = malloc(sizeof(*node));
    if (!node) abort();
    *node = (struct TreeNode){.val = value, .left = NULL, .right = NULL};
    return node;
}

struct TreeNode* deserialize(char* data) {
    const char* next = data;
    struct TreeNode* root = read_node(&next);
    if (!root) return NULL;

    // Every queued node has a token of at least two bytes.
    struct TreeNode** queue = malloc((strlen(data) / 2) * sizeof(*queue));
    if (!queue) abort();
    size_t count = 1;
    queue[0] = root;
    for (size_t i = 0; i < count; ++i) {
        struct TreeNode* parent = queue[i];
        parent->left = read_node(&next);
        parent->right = read_node(&next);
        if (parent->left) queue[count++] = parent->left;
        if (parent->right) queue[count++] = parent->right;
    }
    free(queue);
    return root;
}
