class Trie:
    def __init__(self):
        # Each node is a dict from a letter to the child node; the key "$"
        # marks the end of an inserted word.
        self.root: dict = {}

    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            node = node.setdefault(c, {})
        node["$"] = True

    def _find(self, s: str) -> dict | None:
        node = self.root
        for c in s:
            node = node.get(c)
            if node is None:
                return None
        return node

    def search(self, word: str) -> bool:
        node = self._find(word)
        return node is not None and "$" in node

    def startsWith(self, prefix: str) -> bool:
        return self._find(prefix) is not None
