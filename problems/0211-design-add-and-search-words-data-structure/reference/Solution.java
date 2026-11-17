class WordDictionary {
    private static class TrieNode {
        final TrieNode[] children = new TrieNode[26];
        boolean terminal;
    }

    private final TrieNode root = new TrieNode();

    public void addWord(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word.charAt(i) - 'a';
            if (node.children[index] == null) {
                node.children[index] = new TrieNode();
            }
            node = node.children[index];
        }
        node.terminal = true;
    }

    public boolean search(String word) {
        return matches(root, word, 0);
    }

    private boolean matches(TrieNode node, String word, int index) {
        for (; index < word.length(); index++) {
            char c = word.charAt(index);
            if (c == '.') {
                for (TrieNode child : node.children) {
                    if (child != null && matches(child, word, index + 1)) {
                        return true;
                    }
                }
                return false;
            }
            node = node.children[c - 'a'];
            if (node == null) {
                return false;
            }
        }
        return node.terminal;
    }
}
