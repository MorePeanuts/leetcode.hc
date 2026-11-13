def staircase(rng, n, offset=0, present=False):
    matrix = [[offset + 2*(i+j) for j in range(n)] for i in range(n)]
    return {"matrix": matrix, "target": offset + 2*(n-1) + (0 if present else 1)}
