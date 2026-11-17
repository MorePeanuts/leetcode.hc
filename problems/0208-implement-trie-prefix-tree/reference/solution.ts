class TrieNode {
    readonly children: (TrieNode | undefined)[] = [];
    terminal = false;
}

class Trie {
    private readonly root = new TrieNode();

    insert(word: string): void {
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
        return this.findNode(word)?.terminal ?? false;
    }

    startsWith(prefix: string): boolean {
        return this.findNode(prefix) !== undefined;
    }

    private findNode(word: string): TrieNode | undefined {
        let node: TrieNode | undefined = this.root;
        for (let i = 0; i < word.length && node !== undefined; i++) {
            node = node.children[word.charCodeAt(i) - 97];
        }
        return node;
    }
}
