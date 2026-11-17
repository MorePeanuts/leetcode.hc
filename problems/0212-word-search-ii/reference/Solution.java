import java.util.ArrayList;
import java.util.List;

class Solution {
    private static final int[] DR = {-1, 1, 0, 0};
    private static final int[] DC = {0, 0, -1, 1};

    private static class Node {
        final Node[] children = new Node[26];
        String word;
        int live;
    }

    private int visit(char[][] board, int row, int col, Node node, List<String> result) {
        int found = 0;
        if (node.word != null) {
            result.add(node.word);
            node.word = null;
            ++found;
        }
        char letter = board[row][col];
        board[row][col] = '#';
        for (int dir = 0; dir < 4 && found < node.live; ++dir) {
            int nr = row + DR[dir];
            int nc = col + DC[dir];
            if (nr >= 0 && nr < board.length && nc >= 0 && nc < board[0].length
                    && board[nr][nc] != '#') {
                Node child = node.children[board[nr][nc] - 'a'];
                if (child != null && child.live > 0) {
                    found += visit(board, nr, nc, child, result);
                }
            }
        }
        board[row][col] = letter;
        node.live -= found;
        return found;
    }

    public List<String> findWords(char[][] board, String[] words) {
        Node root = new Node();
        for (String word : words) {
            Node node = root;
            for (int i = 0; i < word.length(); ++i) {
                int letter = word.charAt(i) - 'a';
                if (node.children[letter] == null) {
                    node.children[letter] = new Node();
                }
                node = node.children[letter];
                ++node.live;
            }
            node.word = word;
        }
        List<String> result = new ArrayList<>();
        for (int row = 0; row < board.length && result.size() < words.length; ++row) {
            for (int col = 0; col < board[0].length && result.size() < words.length; ++col) {
                Node child = root.children[board[row][col] - 'a'];
                if (child != null && child.live > 0) {
                    visit(board, row, col, child, result);
                }
            }
        }
        return result;
    }
}
