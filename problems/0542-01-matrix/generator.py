def corner_source(rng, rows, cols):
    mat = [[1] * cols for _ in range(rows)]
    mat[-1][-1] = 0
    return {"mat": mat}


def separated_halves(rng, rows, cols):
    return {"mat": [[0] * (cols // 2) + [1] * (cols - cols // 2) for _ in range(rows)]}
