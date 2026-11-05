LETTERS = "abcdefghijklmnopqrstuvwxyz"


def _random_letters(rng, n, letters=26):
    alphabet = LETTERS[:letters]
    return [rng.choice(alphabet) for _ in range(n)]


def anagram(rng, n, letters=26):
    s = _random_letters(rng, n, letters)
    t = s[:]
    rng.shuffle(t)
    return {"s": "".join(s), "t": "".join(t)}


def sorted_pair(rng, n, letters=26):
    """An anagram: s sorted, t in reverse order."""
    s = sorted(_random_letters(rng, n, letters))
    return {"s": "".join(s), "t": "".join(reversed(s))}


def last_differs(rng, n):
    """Not an anagram, but only at the last letter of s: s is random letters
    from a to x then z, t a shuffle of s with that z made y, so counting the
    letters of s in order finds the difference last."""
    s = _random_letters(rng, n - 1, 24)
    t = s + ["y"]
    rng.shuffle(t)
    return {"s": "".join(s) + "z", "t": "".join(t)}


def same_letter(rng, n):
    return {"s": "a" * n, "t": "a" * n}


def odd_letter_moved(rng, n):
    return {"s": "b" + "a" * (n - 1), "t": "a" * (n - 1) + "b"}
