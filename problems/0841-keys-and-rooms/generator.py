def chain(rng, n):
    return {"rooms": [[i + 1] for i in range(n - 1)] + [[]]}


def reverse_chain(rng, n):
    return {"rooms": [[n - 1], []] + [[i - 1] for i in range(2, n)]}


def dense(rng, n):
    return {"rooms": [[i, (i + 1) % n, (i + 37) % n] for i in range(n)]}
