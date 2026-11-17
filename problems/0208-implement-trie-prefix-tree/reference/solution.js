class TrieNode {
    children = [];
    terminal = false;
}

class Trie {
    root = new TrieNode();

    insert(word) {
        let node = this.root;
        for (let i = 0; i < word.length; i++) {
            const index = word.charCodeAt(i) - 97;
            let child = node.children[index];
            if (child === undefined) {
                child = new TrieNode();
                node.children[index] = child;
            }
            node = child;
        }
        node.terminal = true;
    }

    search(word) {
        return this.findNode(word)?.terminal ?? false;
    }

    startsWith(prefix) {
        return this.findNode(prefix) !== undefined;
    }

    findNode(word) {
        let node = this.root;
        for (let i = 0; i < word.length && node !== undefined; i++) {
            node = node.children[word.charCodeAt(i) - 97];
        }
        return node;
    }
}
