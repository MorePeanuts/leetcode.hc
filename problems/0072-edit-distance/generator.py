import string

LOWER = string.ascii_lowercase


def _random(rng, n, alphabet):
    return "".join(rng.choice(alphabet) for _ in range(n))


def random_pair(rng, m, n, alphabet):
    return {"word1": _random(rng, m, alphabet), "word2": _random(rng, n, alphabet)}


def disjoint(rng, m, n):
    # No common character: every step of a recursion without memoization
    # branches three ways.
    return {"word1": _random(rng, m, LOWER[:13]), "word2": _random(rng, n, LOWER[13:])}


def one_empty(rng, n):
    return {"word1": _random(rng, n, LOWER), "word2": ""}


def few_edits(rng, n, edits):
    # word2 is word1 after `edits` random insertions, deletions and
    # substitutions.
    word1 = _random(rng, n, LOWER)
    w = list(word1)
    for _ in range(edits):
        op = rng.randint(0, 2)
        if op == 0 or len(w) == 0:
            w.insert(rng.randint(0, len(w)), rng.choice(LOWER))
        elif op == 1:
            del w[rng.randint(0, len(w) - 1)]
        else:
            w[rng.randint(0, len(w) - 1)] = rng.choice(LOWER)
    return {"word1": word1, "word2": "".join(w[:500])}


def reversed_pair(rng, n, alphabet):
    s = _random(rng, n, alphabet)
    return {"word1": s, "word2": s[::-1]}


def identical(rng, n):
    s = _random(rng, n, LOWER)
    return {"word1": s, "word2": s}
