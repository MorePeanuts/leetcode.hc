MAX = 10**4


def random_intervals(rng, n, max_len):
    out = []
    for _ in range(n):
        start = rng.randint(0, MAX)
        out.append([start, min(MAX, start + rng.randint(0, max_len))])
    return {"intervals": out}


def disjoint_points(rng, n):
    # n distinct single points [x, x], shuffled: nothing merges, so the
    # answer has n intervals.
    xs = rng.sample(range(0, MAX + 1), n)
    return {"intervals": [[x, x] for x in xs]}


def chain(rng, n):
    # [i, i + 1] shuffled: every neighbor touches, one interval in the end.
    out = [[i, i + 1] for i in range(n)]
    rng.shuffle(out)
    return {"intervals": out}


def nested(rng, n):
    # Intervals nested inside each other around the middle, shuffled.
    mid = MAX // 2
    out = [[mid - i // 2, mid + (i + 1) // 2] for i in range(n)]
    rng.shuffle(out)
    return {"intervals": out}


def all_equal(rng, n, start, end):
    return {"intervals": [[start, end] for _ in range(n)]}


def gaps(rng, n):
    # Pairs [2i, 2i + 1] and [2i + 1, 2i + 1]: each pair merges, and the
    # merged intervals [2i, 2i + 1] and [2i + 2, 2i + 3] do not touch.
    out = []
    for i in range(n // 2):
        a = 2 * i % (MAX - 1)
        out.append([a, a + 1])
        out.append([a + 1, a + 1])
    rng.shuffle(out)
    return {"intervals": out}
