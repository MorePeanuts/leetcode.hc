typedef struct TrieNode {
    struct TrieNode *children[26];
    bool terminal;
} TrieNode;

typedef struct {
    TrieNode root;
} WordDictionary;

WordDictionary *wordDictionaryCreate(void) {
    return calloc(1, sizeof(WordDictionary));
}

void wordDictionaryAddWord(WordDictionary *obj, char *word) {
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

static bool matches(TrieNode *node, const char *word) {
    while (*word != '\0') {
        if (*word == '.') {
            for (int i = 0; i < 26; i++) {
                TrieNode *child = node->children[i];
                if (child != NULL && matches(child, word + 1)) {
                    return true;
                }
            }
            return false;
        }
        node = node->children[*word++ - 'a'];
        if (node == NULL) {
            return false;
        }
    }
    return node->terminal;
}

bool wordDictionarySearch(WordDictionary *obj, char *word) {
    return matches(&obj->root, word);
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

void wordDictionaryFree(WordDictionary *obj) {
    freeChildren(&obj->root);
    free(obj);
}
