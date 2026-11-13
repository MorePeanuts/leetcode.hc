class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3:
            return 0
        prime = bytearray(b"\x01") * n
        prime[0] = prime[1] = 0
        p = 2
        while p * p < n:
            if prime[p]:
                count = (n - 1 - p * p) // p + 1
                prime[p * p:n:p] = bytes(count)
            p += 1
        return sum(prime)
