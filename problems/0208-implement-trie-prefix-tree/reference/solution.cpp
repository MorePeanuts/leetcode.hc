#include <memory>

class Trie {
    struct TrieNode {
        std::unique_ptr<TrieNode> children[26];
        bool terminal = false;
    };

    TrieNode root;

    const TrieNode *findNode(const string &word) const {
        const TrieNode *node = &root;
        for (char c : word) {
            node = node->children[c - 'a'].get();
            if (!node) {
                break;
            }
        }
        return node;
    }

public:
    void insert(string word) {
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
        const TrieNode *node = findNode(word);
        return node && node->terminal;
    }

    bool startsWith(string prefix) {
        return findNode(prefix) != nullptr;
    }
};
