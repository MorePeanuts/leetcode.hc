def equal_run(rng, n):
    return {"head": [0] * n}


def sorted_runs(rng, n):
    return {"head": [i * 201 // n - 100 for i in range(n)]}


def long_prefix(rng, n):
    return {"head": [-100] * (n - 1) + [100]}
