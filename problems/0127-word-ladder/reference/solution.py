from collections import defaultdict, deque

class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        words = set(wordList)
        if endWord not in words:
            return 0
        buckets = defaultdict(list)
        width = len(beginWord)
        for word in words:
            for i in range(width):
                buckets[word[:i] + "*" + word[i+1:]].append(word)
        queue = deque([(beginWord,1)])
        visited = {beginWord}
        while queue:
            word,distance = queue.popleft()
            if word == endWord:
                return distance
            for i in range(width):
                pattern = word[:i] + "*" + word[i+1:]
                for nxt in buckets.pop(pattern, []):
                    if nxt not in visited:
                        visited.add(nxt)
                        queue.append((nxt,distance+1))
        return 0
