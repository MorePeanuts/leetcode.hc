LETTERS = "abcdefghijklmnopqrstuvwxyz"


def two_z_apart(rng, m, n):
    # s1 has two 'z's; in s2 every two 'z's are more than m apart, so no
    # window of length m holds two of them and the answer is false. Every
    # other window is close: s1's other letters are random like s2's.
    s1 = [rng.choice(LETTERS[:25]) for _ in range(m - 2)] + ["z", "z"]
    rng.shuffle(s1)
    s2 = [rng.choice(LETTERS[:25]) for _ in range(n)]
    for i in range(0, n, m + 1):
        s2[i] = "z"
    return {"s1": "".join(s1), "s2": "".join(s2)}


def match_at_end(rng, m, n, letters=25):
    # s1 holds the only 'z'; s2 has no 'z' but in its last m letters, which
    # are a permutation of s1: the only match is at the very end.
    s1 = [rng.choice(LETTERS[:letters]) for _ in range(m - 1)] + ["z"]
    tail = s1[:]
    rng.shuffle(tail)
    rng.shuffle(s1)
    head = [rng.choice(LETTERS[:letters]) for _ in range(n - m)]
    return {"s1": "".join(s1), "s2": "".join(head + tail)}


def one_short(rng, m, n):
    # s1 is m - 1 copies of 'a' and one 'b'; s2 is 'a' with a 'c' at every
    # m-th position: each window is one letter off s1, and none matches.
    s1 = ["a"] * (m - 1) + ["b"]
    rng.shuffle(s1)
    s2 = ["c" if (i + 1) % m == 0 else "a" for i in range(n)]
    return {"s1": "".join(s1), "s2": "".join(s2)}


def random_pair(rng, m, n, letters):
    return {
        "s1": "".join(rng.choice(LETTERS[:letters]) for _ in range(m)),
        "s2": "".join(rng.choice(LETTERS[:letters]) for _ in range(n)),
    }
