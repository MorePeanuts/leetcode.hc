typedef struct TrieNode {
    struct TrieNode *children[26];
    bool terminal;
} TrieNode;

typedef struct {
    TrieNode root;
} Trie;

Trie *trieCreate(void) {
    return calloc(1, sizeof(Trie));
}

void trieInsert(Trie *obj, char *word) {
    TrieNode *node = &obj->root;
    for (const char *c = word; *c != '\0'; c++) {
        int index = *c - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = calloc(1, sizeof(TrieNode));
        }
        node = node->children[index];
    }
    node->terminal = true;
}

static TrieNode *findNode(TrieNode *node, const char *word) {
    for (const char *c = word; *c != '\0' && node != NULL; c++) {
        node = node->children[*c - 'a'];
    }
    return node;
}

bool trieSearch(Trie *obj, char *word) {
    TrieNode *node = findNode(&obj->root, word);
    return node != NULL && node->terminal;
}

bool trieStartsWith(Trie *obj, char *prefix) {
    return findNode(&obj->root, prefix) != NULL;
}

static void freeChildren(TrieNode *node) {
    for (int i = 0; i < 26; i++) {
        TrieNode *child = node->children[i];
        if (child != NULL) {
            freeChildren(child);
            free(child);
        }
    }
}

void trieFree(Trie *obj) {
    freeChildren(&obj->root);
    free(obj);
}
