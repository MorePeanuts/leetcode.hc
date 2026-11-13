package main

func ladderLength(beginWord string, endWord string, wordList []string) int {
	exists := false
	for _, w := range wordList {
		if w == endWord {
			exists = true
			break
		}
	}
	if !exists {
		return 0
	}
	buckets := map[string][]string{}
	for _, w := range wordList {
		for i := range w {
			p := w[:i] + "*" + w[i+1:]
			buckets[p] = append(buckets[p], w)
		}
	}
	type entry struct {
		word     string
		distance int
	}
	queue := []entry{{beginWord, 1}}
	seen := map[string]bool{beginWord: true}
	for head := 0; head < len(queue); head++ {
		v := queue[head]
		if v.word == endWord {
			return v.distance
		}
		for i := range v.word {
			p := v.word[:i] + "*" + v.word[i+1:]
			for _, w := range buckets[p] {
				if !seen[w] {
					seen[w] = true
					queue = append(queue, entry{w, v.distance + 1})
				}
			}
			delete(buckets, p)
		}
	}
	return 0
}
