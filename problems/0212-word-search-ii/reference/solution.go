package main

type trieNode struct {
	children [26]*trieNode
	count    int    // non-nil children
	word     string // the word ending here, "" when none or already found
}

// findWords builds a trie of the words and searches from every cell, last
// cell first, following the board and the trie together. A found word is
// cleared, and a trie node left with nothing below it is dropped.
func findWords(board [][]byte, words []string) []string {
	root := &trieNode{}
	for _, w := range words {
		node := root
		for i := 0; i < len(w); i++ {
			c := w[i] - 'a'
			if node.children[c] == nil {
				node.children[c] = &trieNode{}
				node.count++
			}
			node = node.children[c]
		}
		node.word = w
	}
	m, n := len(board), len(board[0])
	found := []string{}
	var dfs func(i, j int, parent *trieNode)
	dfs = func(i, j int, parent *trieNode) {
		c := board[i][j] - 'a'
		node := parent.children[c]
		if node.word != "" {
			found = append(found, node.word)
			node.word = ""
		}
		board[i][j] = '#'
		if i > 0 && board[i-1][j] != '#' && node.children[board[i-1][j]-'a'] != nil {
			dfs(i-1, j, node)
		}
		if i+1 < m && board[i+1][j] != '#' && node.children[board[i+1][j]-'a'] != nil {
			dfs(i+1, j, node)
		}
		if j > 0 && board[i][j-1] != '#' && node.children[board[i][j-1]-'a'] != nil {
			dfs(i, j-1, node)
		}
		if j+1 < n && board[i][j+1] != '#' && node.children[board[i][j+1]-'a'] != nil {
			dfs(i, j+1, node)
		}
		board[i][j] = c + 'a'
		if node.count == 0 && node.word == "" {
			parent.children[c] = nil
			parent.count--
		}
	}
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if root.children[board[i][j]-'a'] != nil {
				dfs(i, j, root)
			}
		}
	}
	return found
}
