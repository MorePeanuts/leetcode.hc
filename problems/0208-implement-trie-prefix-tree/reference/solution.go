package main

type trieNode struct {
	children [26]*trieNode
	end      bool
}

type Trie struct {
	root *trieNode
}

func Constructor() Trie {
	return Trie{root: &trieNode{}}
}

func (this *Trie) Insert(word string) {
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

func (this *Trie) find(s string) *trieNode {
	node := this.root
	for i := 0; i < len(s) && node != nil; i++ {
		node = node.children[s[i]-'a']
	}
	return node
}

func (this *Trie) Search(word string) bool {
	node := this.find(word)
	return node != nil && node.end
}

func (this *Trie) StartsWith(prefix string) bool {
	return this.find(prefix) != nil
}
