class WordDictionary:
    def __init__(self):
        # Each node is a dict from a letter to the child node; the key "$"
        # marks the end of an added word.
        self.root: dict = {}

    def addWord(self, word: str) -> None:
        node = self.root
        for c in word:
            node = node.setdefault(c, {})
        node["$"] = True

    def search(self, word: str) -> bool:
        # The nodes the pattern's prefix read so far reaches, level by level:
        # a dot follows every child, so with at most two dots there are at
        # most 26 * 26 of them.
        nodes = [self.root]
        for c in word:
            if c == ".":
                nodes = [child for node in nodes for k, child in node.items() if k != "$"]
            else:
                nodes = [node[c] for node in nodes if c in node]
            if not nodes:
                return False
        return any("$" in node for node in nodes)
