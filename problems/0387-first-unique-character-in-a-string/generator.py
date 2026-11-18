def repeated_prefix(rng, n, char):
    return {"s": char * (n - 1) + "z"}


def letter_blocks(rng, n, split, first, second):
    # Both long blocks have duplicates, so the second block scans the first.
    return {"s": first * split + second * (n - split)}
