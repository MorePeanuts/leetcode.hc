LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"


def planted(rng, m, n, letters, extra, at_end):
    # t is n random letters from the first `letters` of LETTERS. s holds one
    # block that covers t: t's letters shuffled, `extra` other letters mixed
    # in, and anchors at both ends; around it, letters that are never
    # anchors. Every window that covers t holds all the anchors of s, so it
    # holds the block: the block is the unique answer.
    t = [rng.choice(LETTERS[:letters]) for _ in range(n)]
    counts = {}
    for ch in t:
        counts[ch] = counts.get(ch, 0) + 1
    rest = t[:]
    if n == 1:
        anchors = [t[0]]
        first, last = t[0], None
        rest = []
    else:
        twice = sorted(ch for ch, k in counts.items() if k >= 2)
        if twice:
            # Both ends are the same letter, and s has no other copy of it.
            x = rng.choice(twice)
            anchors = [x]
            first, last = x, x
        else:
            # All distinct: two letters that appear nowhere else in s.
            first, last = rng.sample(sorted(counts), 2)
            anchors = [first, last]
        rest.remove(first)
        rest.remove(last)
    others = [ch for ch in LETTERS if ch not in anchors]
    middle = rest + [rng.choice(others) for _ in range(extra)]
    rng.shuffle(middle)
    block = [first] + middle + ([last] if last is not None else [])
    outside = m - len(block)
    head = outside if at_end else rng.randint(0, outside)
    s = [rng.choice(others) for _ in range(head)] + block
    s += [rng.choice(others) for _ in range(outside - head)]
    return {"s": "".join(s), "t": "".join(t)}


def missing_letter(rng, m, n, letters):
    # t holds one letter that s lacks: the answer is "".
    t = [rng.choice(LETTERS[:letters]) for _ in range(n - 1)] + ["z"]
    rng.shuffle(t)
    s = [rng.choice(LETTERS[:letters]) for _ in range(m)]
    s = [ch if ch != "z" else "y" for ch in s]
    return {"s": "".join(s), "t": "".join(t)}


def permutation(rng, n):
    # s is a permutation of t: the whole of s is the answer.
    t = [rng.choice(LETTERS) for _ in range(n)]
    s = t[:]
    rng.shuffle(s)
    return {"s": "".join(s), "t": "".join(t)}
