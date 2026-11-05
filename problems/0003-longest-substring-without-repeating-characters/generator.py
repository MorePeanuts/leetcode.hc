PRINTABLE = [chr(c) for c in range(32, 127)]


def random_chars(rng, n, alphabet):
    # alphabet: "printable" (every character the constraints allow),
    # "lower" or "digits".
    chars = {
        "printable": PRINTABLE,
        "lower": [chr(c) for c in range(ord("a"), ord("z") + 1)],
        "digits": [chr(c) for c in range(ord("0"), ord("9") + 1)],
    }[alphabet]
    return {"s": "".join(rng.choice(chars) for _ in range(n))}


def cycle(rng, n):
    # Every allowed character in turn, repeated: every window of 95 is the
    # answer, and a duplicate is always 95 characters back.
    return {"s": "".join(PRINTABLE[i % len(PRINTABLE)] for i in range(n))}


def all_equal(rng, n):
    return {"s": "a" * n}


def distinct_at_end(rng, n):
    # Two characters alternating, then all 95 characters once: the only
    # window of 95 is at the very end.
    head = "".join("ab"[i % 2] for i in range(n - len(PRINTABLE)))
    tail = [c for c in PRINTABLE if c not in "ab"]
    return {"s": head + "".join(tail) + ("ba" if head.endswith("a") else "ab")}
