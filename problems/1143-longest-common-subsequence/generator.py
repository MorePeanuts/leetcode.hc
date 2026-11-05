import string

LOWER = string.ascii_lowercase


def _random(rng, n, alphabet):
    return "".join(rng.choice(alphabet) for _ in range(n))


def random_pair(rng, m, n, alphabet):
    return {"text1": _random(rng, m, alphabet), "text2": _random(rng, n, alphabet)}


def disjoint(rng, m, n):
    # No common character: the answer is 0, and a recursion without
    # memoization explores every path through the m x n grid.
    return {"text1": _random(rng, m, LOWER[:13]), "text2": _random(rng, n, LOWER[13:])}


def identical(rng, n, alphabet):
    s = _random(rng, n, alphabet)
    return {"text1": s, "text2": s}


def subsequence(rng, n, k):
    # text2 is a random subsequence of length k of text1: the answer is k.
    text1 = _random(rng, n, LOWER)
    keep = sorted(rng.sample(range(n), k))
    return {"text1": text1, "text2": "".join(text1[i] for i in keep)}


def reversed_pair(rng, n, alphabet):
    s = _random(rng, n, alphabet)
    return {"text1": s, "text2": s[::-1]}


def repeated(rng, m, n):
    return {"text1": "a" * m, "text2": "a" * n}
