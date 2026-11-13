class Solution:
    def decodeString(self, s):
        stack = []
        current = ""
        repeat = 0
        for ch in s:
            if ch.isdigit():
                repeat = repeat * 10 + int(ch)
            elif ch == "[":
                stack.append((current, repeat))
                current, repeat = "", 0
            elif ch == "]":
                prefix, count = stack.pop()
                current = prefix + current * count
            else:
                current += ch
        return current
