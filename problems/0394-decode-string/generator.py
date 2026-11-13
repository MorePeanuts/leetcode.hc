def expanded_limit(rng, n, mode):
    # The encoded input is short; generation avoids storing a 100 KB expected string.
    if mode == 0:
        s = f"{n}[100[abcdefghij]]"
    elif mode == 1:
        s = f"{n}[300[a]]"
    else:
        s = f"{n}[99[abcdefghij]klmnopqrst]"
    return {"s": s}
