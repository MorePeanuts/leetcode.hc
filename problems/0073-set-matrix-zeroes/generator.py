def matrix(rng, m, n, mode):
    a = [[2147483647] * n for _ in range(m)]
    if mode == "last":
        a[-1][-1] = 0
    elif mode == "diagonal":
        for i in range(min(m, n)):
            a[i][i] = 0
    return {"matrix": a}


def dense_zeroes(rng, m, n, mode):
    if mode == "all":
        a = [[0] * n for _ in range(m)]
    elif mode == "checkerboard":
        a = [[0 if (r + c) % 2 == 0 else 7 for c in range(n)] for r in range(m)]
    else:
        # Leave one row and column unmarked to retain a nonzero output cell.
        a = [[0 if r < m - 1 and c < n - 1 else -9 for c in range(n)] for r in range(m)]
    return {"matrix": a}
