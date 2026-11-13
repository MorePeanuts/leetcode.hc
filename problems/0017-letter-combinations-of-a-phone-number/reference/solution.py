class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        letters = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl",
                   "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
        result = [""]
        for digit in digits:
            result = [prefix + letter for prefix in result for letter in letters[digit]]
        return result
