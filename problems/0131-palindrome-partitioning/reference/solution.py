class Solution:
    def partition(self, s: str) -> list[list[str]]:
        n = len(s)
        palindrome = [[False] * n for _ in range(n)]
        for start in range(n - 1, -1, -1):
            for end in range(start, n):
                palindrome[start][end] = s[start] == s[end] and (end - start < 2 or palindrome[start + 1][end - 1])
        answer = []
        path = []
        def search(start):
            if start == n:
                answer.append(path.copy())
                return
            for end in range(start, n):
                if palindrome[start][end]:
                    path.append(s[start:end + 1])
                    search(end + 1)
                    path.pop()
        search(0)
        return answer
