class Solution:
    def equationsPossible(self, equations: list[str]) -> bool:
        parent = list(range(26))
        size = [1] * 26

        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        for equation in equations:
            if equation[1] == "=":
                a = find(ord(equation[0]) - 97)
                b = find(ord(equation[3]) - 97)
                if a != b:
                    if size[a] < size[b]:
                        a, b = b, a
                    parent[b] = a
                    size[a] += size[b]
        return all(find(ord(e[0]) - 97) != find(ord(e[3]) - 97)
                   for e in equations if e[1] == "!")
