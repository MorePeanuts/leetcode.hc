def constant(rng, n, value):
    return {"grid": [[value] * n for _ in range(n)]}

def patterned(rng, n):
    return {"grid": [[(17 * i + 31 * j) % 201 for j in range(n)] for i in range(n)]}
