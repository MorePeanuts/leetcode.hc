typedef struct {
    int child[26];
    int live;
    int word;
} TrieNode;

static int visit(char** board, int rows, int cols, int row, int col,
                 TrieNode* trie, int index, char** words, char** result, int* size) {
    char letter = board[row][col];
    TrieNode* node = &trie[index];
    int found = 0;
    if (node->word != 0) {
        const char* word = words[node->word - 1];
        size_t len = strlen(word) + 1;
        char* copy = malloc(len);
        memcpy(copy, word, len);
        result[(*size)++] = copy;
        node->word = 0;
        ++found;
    }
    board[row][col] = '#';
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};
    for (int dir = 0; dir < 4 && found < node->live; ++dir) {
        int nr = row + dr[dir];
        int nc = col + dc[dir];
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] != '#') {
            int child = node->child[board[nr][nc] - 'a'];
            if (child != 0 && trie[child].live > 0) {
                found += visit(board, rows, cols, nr, nc, trie, child, words, result, size);
            }
        }
    }
    board[row][col] = letter;
    node->live -= found;
    return found;
}

char** findWords(char** board, int boardSize, int* boardColSize,
                 char** words, int wordsSize, int* returnSize) {
    size_t capacity = 1;
    for (int i = 0; i < wordsSize; ++i) {
        capacity += strlen(words[i]);
    }
    TrieNode* trie = calloc(capacity, sizeof(*trie));
    int used = 1;
    for (int i = 0; i < wordsSize; ++i) {
        int node = 0;
        for (int j = 0; words[i][j]; ++j) {
            int letter = words[i][j] - 'a';
            if (trie[node].child[letter] == 0) {
                trie[node].child[letter] = used++;
            }
            node = trie[node].child[letter];
            ++trie[node].live;
        }
        trie[node].word = i + 1;
    }
    char** result = malloc((size_t)wordsSize * sizeof(*result));
    *returnSize = 0;
    int cols = boardColSize[0];
    for (int row = 0; row < boardSize && *returnSize < wordsSize; ++row) {
        for (int col = 0; col < cols && *returnSize < wordsSize; ++col) {
            int child = trie[0].child[board[row][col] - 'a'];
            if (child != 0 && trie[child].live > 0) {
                visit(board, boardSize, cols, row, col, trie, child, words, result, returnSize);
            }
        }
    }
    free(trie);
    return result;
}
