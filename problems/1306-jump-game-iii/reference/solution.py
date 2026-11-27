class Solution:
    def canReach(self, arr: list[int], start: int) -> bool:
        seen = bytearray(len(arr))
        seen[start] = 1
        stack = [start]
        while stack:
            i = stack.pop()
            if arr[i] == 0:
                return True
            for j in (i - arr[i], i + arr[i]):
                if 0 <= j < len(arr) and not seen[j]:
                    seen[j] = 1
                    stack.append(j)
        return False
