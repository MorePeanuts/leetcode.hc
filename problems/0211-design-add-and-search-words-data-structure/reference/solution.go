package main

type trieNode struct {
	children [26]*trieNode
	end      bool
}

type WordDictionary struct {
	root *trieNode
}

func Constructor() WordDictionary {
	return WordDictionary{root: &trieNode{}}
}

func (this *WordDictionary) AddWord(word string) {
	node := this.root
	for i := 0; i < len(word); i++ {
		c := word[i] - 'a'
		if node.children[c] == nil {
			node.children[c] = &trieNode{}
		}
		node = node.children[c]
	}
	node.end = true
}

func (this *WordDictionary) Search(word string) bool {
	return match(this.root, word, 0)
}

// match reports whether a word below node matches word[i:], trying each
// child in turn at a dot.
func match(node *trieNode, word string, i int) bool {
	for ; i < len(word); i++ {
		if word[i] == '.' {
			for _, child := range node.children {
				if child != nil && match(child, word, i+1) {
					return true
				}
			}
			return false
		}
		node = node.children[word[i]-'a']
		if node == nil {
			return false
		}
	}
	return node.end
}
