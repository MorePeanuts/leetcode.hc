LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"


def random_letters(rng, n, letters, k):
    # Random letters from the first `letters` of the alphabet.
    return {"s": "".join(rng.choice(LETTERS[:letters]) for _ in range(n)), "k": k}


def all_same(rng, n, k):
    return {"s": "Q" * n, "k": k}


def mostly_one(rng, n, k, other):
    # Mostly 'A', with `other` random positions of other letters: the answer
    # depends on how many of them k can cover.
    s = ["A"] * n
    for i in rng.sample(range(n), other):
        s[i] = rng.choice(LETTERS[1:])
    return {"s": "".join(s), "k": k}


def cycle(rng, n, k):
    # All 26 letters in turn: no letter is more than 1/26 of any window.
    return {"s": "".join(LETTERS[i % 26] for i in range(n)), "k": k}


def run_at_end(rng, n, k):
    # Random letters, then a long run of 'Z' with a few holes at the end:
    # the best window is at the very end.
    head = n * 3 // 5
    s = [rng.choice(LETTERS[:25]) for _ in range(head)]
    tail = ["Z"] * (n - head)
    for i in rng.sample(range(n - head), k):
        tail[i] = rng.choice(LETTERS[:25])
    return {"s": "".join(s + tail), "k": k}
