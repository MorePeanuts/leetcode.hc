class Solution {
    struct TrieNode {
        std::array<int, 26> child{};
        int live = 0;
        int word = -1;
    };

    int visit(std::vector<std::vector<char>>& board, int row, int col,
              std::vector<TrieNode>& trie, int index,
              const std::vector<std::string>& words, std::vector<std::string>& result) {
        auto& node = trie[index];
        int found = 0;
        if (node.word >= 0) {
            result.push_back(words[node.word]);
            node.word = -1;
            ++found;
        }
        char letter = board[row][col];
        board[row][col] = '#';
        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};
        for (int dir = 0; dir < 4 && found < node.live; ++dir) {
            int nr = row + dr[dir];
            int nc = col + dc[dir];
            if (nr >= 0 && nr < static_cast<int>(board.size())
                    && nc >= 0 && nc < static_cast<int>(board[0].size())
                    && board[nr][nc] != '#') {
                int child = node.child[board[nr][nc] - 'a'];
                if (child != 0 && trie[child].live > 0) {
                    found += visit(board, nr, nc, trie, child, words, result);
                }
            }
        }
        board[row][col] = letter;
        node.live -= found;
        return found;
    }

public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board,
                                       std::vector<std::string>& words) {
        std::vector<TrieNode> trie(1);
        for (int i = 0; i < static_cast<int>(words.size()); ++i) {
            int index = 0;
            for (char letter : words[i]) {
                int child = trie[index].child[letter - 'a'];
                if (child == 0) {
                    child = static_cast<int>(trie.size());
                    trie[index].child[letter - 'a'] = child;
                    trie.emplace_back();
                }
                index = child;
                ++trie[index].live;
            }
            trie[index].word = i;
        }
        std::vector<std::string> result;
        for (int row = 0; row < static_cast<int>(board.size()) && result.size() < words.size(); ++row) {
            for (int col = 0; col < static_cast<int>(board[0].size()) && result.size() < words.size(); ++col) {
                int child = trie[0].child[board[row][col] - 'a'];
                if (child != 0 && trie[child].live > 0) {
                    visit(board, row, col, trie, child, words, result);
                }
            }
        }
        return result;
    }
};
