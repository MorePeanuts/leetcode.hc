# Matrices of m rows and n columns (1 <= m, n <= 100) whose rows, read one
# after another, are non-decreasing, with every row's first value greater
# than the previous row's last one; values in [-10^4, 10^4].


def _matrix(rng, m, n, dups):
    # m * n distinct sorted values drawn from the range, cut into rows. With
    # dups, each value after the first of its row repeats its left neighbour
    # with probability 1/2: the rows stay non-decreasing, and every row's
    # first value stays greater than the previous row's last.
    values = sorted(rng.sample(range(-10**4, 10**4 + 1), m * n))
    rows = [values[i * n:(i + 1) * n] for i in range(m)]
    if dups:
        for row in rows:
            for j in range(1, n):
                if rng.randint(0, 1):
                    row[j] = row[j - 1]
    return rows


def present(rng, m, n, dups, at):
    # A target the matrix holds: "first" (the smallest), "last" (the
    # largest), "row_start" (the first value of a row other than the first),
    # "row_end" (the last value of a row other than the last), or "random".
    matrix = _matrix(rng, m, n, dups)
    if at == "first":
        target = matrix[0][0]
    elif at == "last":
        target = matrix[-1][-1]
    elif at == "row_start":
        target = matrix[rng.randint(1, m - 1)][0]
    elif at == "row_end":
        target = matrix[rng.randint(0, m - 2)][-1]
    else:
        target = matrix[rng.randint(0, m - 1)][rng.randint(0, n - 1)]
    return {"matrix": matrix, "target": target}


def absent(rng, m, n, at):
    # A target the matrix lacks: "between_rows" (between a row's last value
    # and the next row's first), "inside" (between two values of a row), or
    # "random" (any value of the range the matrix lacks). At most 10^4 of the
    # range's 20001 values are held, so the last kind always exists, and it
    # stands in for the others when they have no gap.
    matrix = _matrix(rng, m, n, False)
    if at == "between_rows":
        gaps = [
            v
            for i in range(m - 1)
            for v in range(matrix[i][-1] + 1, matrix[i + 1][0])
        ]
    elif at == "inside":
        gaps = [
            v
            for row in matrix
            for a, b in zip(row, row[1:])
            for v in range(a + 1, b)
        ]
    else:
        gaps = []
    if not gaps:
        held = set(v for row in matrix for v in row)
        gaps = [v for v in range(-10**4, 10**4 + 1) if v not in held]
    return {"matrix": matrix, "target": rng.choice(gaps)}
