class Trie {
    private static class TrieNode {
        final TrieNode[] children = new TrieNode[26];
        boolean terminal;
    }

    private final TrieNode root = new TrieNode();

    public void insert(String word) {
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
        TrieNode node = findNode(word);
        return node != null && node.terminal;
    }

    public boolean startsWith(String prefix) {
        return findNode(prefix) != null;
    }

    private TrieNode findNode(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length() && node != null; i++) {
            node = node.children[word.charAt(i) - 'a'];
        }
        return node;
    }
}
