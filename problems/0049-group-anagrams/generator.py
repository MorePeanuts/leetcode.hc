LETTERS = "abcdefghijklmnopqrstuvwxyz"


def short_strings(rng, n, letters, max_len):
    """n strings of lengths 0 to max_len over the first `letters` letters."""
    alphabet = LETTERS[:letters]
    return {
        "strs": [
            "".join(rng.choice(alphabet) for _ in range(rng.randint(0, max_len)))
            for _ in range(n)
        ]
    }


def permuted_words(rng, n, words, max_len):
    """n shuffles of `words` random words of lengths 1 to max_len."""
    base = [
        "".join(rng.choice(LETTERS) for _ in range(rng.randint(1, max_len)))
        for _ in range(words)
    ]
    strs = []
    for _ in range(n):
        s = list(rng.choice(base))
        rng.shuffle(s)
        strs.append("".join(s))
    return {"strs": strs}


def random_strings(rng, n, length):
    """n random strings of one length, nearly all in groups of one."""
    return {
        "strs": ["".join(rng.choice(LETTERS) for _ in range(length)) for _ in range(n)]
    }


def one_word(rng, n, length):
    """n shuffles of the first `length` letters: one group of n."""
    strs = []
    for _ in range(n):
        s = list(LETTERS[:length])
        rng.shuffle(s)
        strs.append("".join(s))
    return {"strs": strs}


def empty_strings(rng, n):
    """n empty strings: one group of n."""
    return {"strs": [""] * n}


def long_strings(rng, n, length, groups):
    """n shuffles of `groups` words of one length; word i has exactly i
    letters 'a', so the groups are distinct."""
    base = [
        "a" * i + "".join(rng.choice(LETTERS[1:]) for _ in range(length - i))
        for i in range(groups)
    ]
    strs = []
    for _ in range(n):
        s = list(rng.choice(base))
        rng.shuffle(s)
        strs.append("".join(s))
    return {"strs": strs}
