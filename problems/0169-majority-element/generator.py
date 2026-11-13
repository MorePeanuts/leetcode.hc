def late_majority(rng, n, value):
    minority = list(range(1, n // 2))
    return {"nums": minority + [value] * (n - len(minority))}
