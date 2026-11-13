def additive(rng, n, k, step_row=1, step_col=1, offset=0):
    return {"matrix": [[offset + i * step_row + j * step_col for j in range(n)]
                       for i in range(n)], "k": k}


def monotone_random(rng, n, k):
    rows = sorted(rng.randint(-500000000, 500000000) for _ in range(n))
    cols = sorted(rng.randint(-500000000, 500000000) for _ in range(n))
    return {"matrix": [[a + b for b in cols] for a in rows], "k": k}
