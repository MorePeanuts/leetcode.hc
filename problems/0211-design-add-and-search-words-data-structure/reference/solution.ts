class TrieNode {
    readonly children: (TrieNode | undefined)[] = [];
    terminal = false;
}

class WordDictionary {
    private readonly root = new TrieNode();

    addWord(word: string): void {
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

    search(word: string): boolean {
        return this.matches(this.root, word, 0);
    }

    private matches(start: TrieNode, word: string, index: number): boolean {
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
