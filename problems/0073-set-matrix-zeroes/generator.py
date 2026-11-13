def matrix(rng, m, n, mode):
    a = [[2147483647] * n for _ in range(m)]
    if mode == "last":
        a[-1][-1] = 0
    elif mode == "diagonal":
        for i in range(min(m, n)):
            a[i][i] = 0
    return {"matrix": a}
