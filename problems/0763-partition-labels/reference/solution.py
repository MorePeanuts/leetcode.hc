class Solution:
    def partitionLabels(self, s: str) -> list[int]:
        last = {letter: index for index, letter in enumerate(s)}
        answer = []
        start = end = 0
        for index, letter in enumerate(s):
            end = max(end, last[letter])
            if index == end:
                answer.append(end - start + 1)
                start = index + 1
        return answer
