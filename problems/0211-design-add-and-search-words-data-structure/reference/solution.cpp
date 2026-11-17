#include <memory>

class WordDictionary {
    struct TrieNode {
        std::unique_ptr<TrieNode> children[26];
        bool terminal = false;
    };

    TrieNode root;

    static bool matches(const TrieNode *node, const string &word, size_t index) {
        for (; index < word.size(); index++) {
            char c = word[index];
            if (c == '.') {
                for (const auto &child : node->children) {
                    if (child && matches(child.get(), word, index + 1)) {
                        return true;
                    }
                }
                return false;
            }
            node = node->children[c - 'a'].get();
            if (!node) {
                return false;
            }
        }
        return node->terminal;
    }

public:
    void addWord(string word) {
        TrieNode *node = &root;
        for (char c : word) {
            auto &child = node->children[c - 'a'];
            if (!child) {
                child = std::make_unique<TrieNode>();
            }
            node = child.get();
        }
        node->terminal = true;
    }

    bool search(string word) {
        return matches(&root, word, 0);
    }
};
