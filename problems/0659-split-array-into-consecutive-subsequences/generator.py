def parallel_runs(rng, copies, extra):
    nums = [value for value in (-1, 0, 1) for _ in range(copies)]
    if extra:
        nums.append(2)
    return {"nums": nums}


def short_last_group(rng, copies):
    return {"nums": [-1] * copies + [0] * copies + [1] * (copies - 1)}


def wide_range(rng, copies):
    return {"nums": [value for value in range(-1000, 1001) for _ in range(copies)]}


def separated_triples(rng, groups, copies):
    nums = []
    for group in range(groups):
        start = -1000 + group * 4
        for value in range(start, start + 3):
            nums.extend([value] * copies)
    return {"nums": nums}
