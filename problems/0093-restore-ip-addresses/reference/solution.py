class Solution:
    def restoreIpAddresses(self, s: str) -> list[str]:
        answer = []
        parts = []
        def visit(start):
            remaining = 4 - len(parts)
            if not remaining <= len(s) - start <= 3 * remaining:
                return
            if remaining == 0:
                answer.append(".".join(parts))
                return
            for length in range(1, 4):
                part = s[start:start + length]
                if len(part) != length:
                    break
                if (length > 1 and part[0] == "0") or int(part) > 255:
                    break
                parts.append(part)
                visit(start + length)
                parts.pop()
        visit(0)
        return answer
