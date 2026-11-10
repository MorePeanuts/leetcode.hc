class Solution:
    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        # A trie of the words; the key "$" of a node holds the word ending
        # there. One search from each cell follows the board and the trie
        # together, removes each word once found, and drops the trie nodes
        # left with nothing below them.
        root: dict = {}
        for w in words:
            node = root
            for c in w:
                node = node.setdefault(c, {})
            node["$"] = w
        m, n = len(board), len(board[0])
        found: list[str] = []

        def dfs(i: int, j: int, parent: dict) -> None:
            c = board[i][j]
            node = parent[c]
            w = node.pop("$", None)
            if w is not None:
                found.append(w)
            board[i][j] = "#"
            for ni, nj in ((i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)):
                if 0 <= ni < m and 0 <= nj < n and board[ni][nj] in node:
                    dfs(ni, nj, node)
            board[i][j] = c
            if not node:
                del parent[c]

        for i in range(m):
            for j in range(n):
                if board[i][j] in root:
                    dfs(i, j, root)
        return found
