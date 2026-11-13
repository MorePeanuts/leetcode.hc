from collections import Counter


def check(input, output, expected):
    if not isinstance(output, list) or len(output) != input["k"]:
        return "Return exactly k pairs."
    counts1 = Counter(input["nums1"])
    counts2 = Counter(input["nums2"])
    used = Counter()
    total = 0
    for position, pair in enumerate(output):
        if (not isinstance(pair, list) or len(pair) != 2
                or any(type(value) is not int for value in pair)):
            return f"Pair {position} must contain exactly two integers."
        u, v = pair
        if u not in counts1 or v not in counts2:
            return f"Pair {position} must take its first value from nums1 and second from nums2."
        used[u, v] += 1
        if used[u, v] > counts1[u] * counts2[v]:
            return f"Pair {pair} occurs more often than its available index pairs."
        total += u + v
    # Valid k-element submultisets have minimal total exactly when they
    # select k smallest pair sums. This allows all ties and output orders.
    optimum = sum(u + v for u, v in expected)
    if total != optimum:
        return f"Pair sums total {total}; the minimum total for k pairs is {optimum}."
    return True
