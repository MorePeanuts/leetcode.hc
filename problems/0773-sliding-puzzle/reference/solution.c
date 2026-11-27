typedef struct {
    unsigned char tiles[6];
} Board;

static int encodeBoard(const Board* board) {
    int code = 0;
    for (int i = 0; i < 6; i++) code = code * 6 + board->tiles[i];
    return code;
}

int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
    const int neighbors[6][3] = {
        {1, 3, -1}, {0, 2, 4}, {1, 5, -1}, {0, 4, -1}, {1, 3, 5}, {2, 4, -1}
    };
    const Board target = {{1, 2, 3, 4, 5, 0}};
    Board queue[720];
    bool seen[46656] = {false};  // Six base-6 digits.
    for (int i = 0; i < 6; i++) queue[0].tiles[i] = board[i / 3][i % 3];
    seen[encodeBoard(&queue[0])] = true;
    int head = 0, tail = 1;
    for (int moves = 0; head < tail; moves++) {
        int end = tail;
        while (head < end) {
            Board current = queue[head++];
            if (memcmp(current.tiles, target.tiles, 6) == 0) return moves;
            int blank = 0;
            while (current.tiles[blank] != 0) blank++;
            for (int i = 0; i < 3 && neighbors[blank][i] >= 0; i++) {
                int to = neighbors[blank][i];
                Board next = current;
                next.tiles[blank] = next.tiles[to];
                next.tiles[to] = 0;
                int code = encodeBoard(&next);
                if (!seen[code]) {
                    seen[code] = true;
                    queue[tail++] = next;
                }
            }
        }
    }
    return -1;
}
