function slidingPuzzle(board: number[][]): number {
    const neighbors = [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]];
    const start = board.flat().join("");
    const queue = [start];
    const seen = new Set(queue);
    let head = 0;
    for (let moves = 0; head < queue.length; moves++) {
        const end = queue.length;
        while (head < end) {
            const current = queue[head++];
            if (current === "123450") return moves;
            const blank = current.indexOf("0");
            for (const to of neighbors[blank]) {
                const tiles = current.split("");
                tiles[blank] = tiles[to];
                tiles[to] = "0";
                const next = tiles.join("");
                if (!seen.has(next)) {
                    seen.add(next);
                    queue.push(next);
                }
            }
        }
    }
    return -1;
}
