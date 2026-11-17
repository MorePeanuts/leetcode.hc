type TrieNode = { children: Map<string, TrieNode>; word: string | null; live: number };

function findWords(board: string[][], words: string[]): string[] {
    function makeNode(): TrieNode {
        return { children: new Map(), word: null, live: 0 };
    }

    const root = makeNode();
    for (const word of words) {
        let node = root;
        for (const letter of word) {
            let child = node.children.get(letter);
            if (child === undefined) {
                child = makeNode();
                node.children.set(letter, child);
            }
            node = child;
            ++node.live;
        }
        node.word = word;
    }

    const rows = board.length;
    const cols = board[0].length;
    const dr = [-1, 1, 0, 0];
    const dc = [0, 0, -1, 1];
    const result: string[] = [];
    function visit(row: number, col: number, node: TrieNode): number {
        let found = 0;
        if (node.word !== null) {
            result.push(node.word);
            node.word = null;
            ++found;
        }
        const letter = board[row][col];
        board[row][col] = "#";
        for (let dir = 0; dir < 4 && found < node.live; ++dir) {
            const nr = row + dr[dir];
            const nc = col + dc[dir];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                const child = node.children.get(board[nr][nc]);
                if (child !== undefined && child.live > 0) {
                    found += visit(nr, nc, child);
                }
            }
        }
        board[row][col] = letter;
        node.live -= found;
        return found;
    }
    for (let row = 0; row < rows && result.length < words.length; ++row) {
        for (let col = 0; col < cols && result.length < words.length; ++col) {
            const child = root.children.get(board[row][col]);
            if (child !== undefined && child.live > 0) {
                visit(row, col, child);
            }
        }
    }
    return result;
}
