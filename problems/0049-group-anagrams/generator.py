LETTERS = "abcdefghijklmnopqrstuvwxyz"


def random_strings(rng, n, length, letters=26):
    """n random strings of one length over the first `letters` letters: over
    all 26, nearly all in groups of one."""
    alphabet = LETTERS[:letters]
    return {
        "strs": ["".join(rng.choice(alphabet) for _ in range(length)) for _ in range(n)]
    }


def shuffled_groups(rng, n, groups, length):
    """n shuffles of `groups` random words of one length, in random order."""
    base = ["".join(rng.choice(LETTERS) for _ in range(length)) for _ in range(groups)]
    strs = []
    for _ in range(n):
        s = list(rng.choice(base))
        rng.shuffle(s)
        strs.append("".join(s))
    return {"strs": strs}
