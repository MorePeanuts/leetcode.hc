LETTERS = "abcdefghijklmnopqrstuvwxyz"


def _random_letters(rng, n):
    return [rng.choice(LETTERS) for _ in range(n)]


def anagram(rng, n):
    s = _random_letters(rng, n)
    t = s[:]
    rng.shuffle(t)
    return {"s": "".join(s), "t": "".join(t)}


def one_changed(rng, n):
    s = _random_letters(rng, n)
    t = s[:]
    rng.shuffle(t)
    i = rng.randint(0, n - 1)
    t[i] = LETTERS[(LETTERS.index(t[i]) + rng.randint(1, 25)) % 26]
    return {"s": "".join(s), "t": "".join(t)}


def one_shorter(rng, n):
    s = _random_letters(rng, n)
    t = s[:]
    rng.shuffle(t)
    return {"s": "".join(s), "t": "".join(t[:-1])}


def same_letter(rng, n):
    return {"s": "a" * n, "t": "a" * n}


def odd_letter_moved(rng, n):
    return {"s": "b" + "a" * (n - 1), "t": "a" * (n - 1) + "b"}


def counts_off_by_one(rng, n):
    h = n // 2
    return {"s": "a" * h + "b" * (n - h), "t": "a" * (h + 1) + "b" * (n - h - 1)}
