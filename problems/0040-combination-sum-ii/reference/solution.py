class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
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
                if i > start and value == candidates[i - 1]:
                    continue
                path.append(value)
                search(i + 1, remaining - value)
                path.pop()
        search(0, target)
        return answer
