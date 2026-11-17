class TrieNode {
    children = [];
    terminal = false;
}

class WordDictionary {
    root = new TrieNode();

    addWord(word) {
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
        return this.matches(this.root, word, 0);
    }

    matches(start, word, index) {
        let node = start;
        for (; index < word.length; index++) {
            if (word[index] === ".") {
                for (const child of node.children) {
                    if (child !== undefined && this.matches(child, word, index + 1)) {
                        return true;
                    }
                }
                return false;
            }
            const child = node.children[word.charCodeAt(index) - 97];
            if (child === undefined) {
                return false;
            }
            node = child;
        }
        return node.terminal;
    }
}
