class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        candidates.sort()
        answer = []
        path = []
        def search(start, remaining):
            if remaining == 0:
                answer.append(path.copy())
                return
            for i in range(start, len(candidates)):
                value = candidates[i]
                if value > remaining:
                    break
                path.append(value)
                search(i, remaining - value)
                path.pop()
        search(0, target)
        return answer
