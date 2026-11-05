def _rotated(rng, n, k):
    values = sorted(rng.sample(range(-10**4, 10**4 + 1), n))
    return values[k:] + values[:k]


def rotated(rng, n, k, at):
    # A sorted array of n distinct values rotated left by k (0 for none), and
    # a target at the given place: "first", "last", "pivot" (the smallest
    # value), "before_pivot" (the largest), "random", or "absent" (a value
    # between two of the array's, or outside them when there is no gap).
    nums = _rotated(rng, n, k)
    if at == "first":
        target = nums[0]
    elif at == "last":
        target = nums[-1]
    elif at == "pivot":
        target = min(nums)
    elif at == "before_pivot":
        target = max(nums)
    elif at == "random":
        target = rng.choice(nums)
    else:
        values = sorted(nums)
        gaps = [v + 1 for v, w in zip(values, values[1:]) if w - v > 1]
        if gaps:
            target = rng.choice(gaps)
        elif values[0] > -10**4:
            target = values[0] - 1
        else:
            target = values[-1] + 1
    return {"nums": nums, "target": target}
