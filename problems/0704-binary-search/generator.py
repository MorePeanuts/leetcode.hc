def spaced(rng, n, at):
    # Odd values keep both endpoints legal at n = 10000, with internal gaps.
    nums = [-9999 + 2 * i for i in range(n)]
    if at == "last":
        target = nums[-1]
    elif at == "near_last":
        target = nums[-2]
    else:
        target = nums[-1] - 1
    return {"nums": nums, "target": target}


def irregular(rng, n, present):
    # Exclude a high target before sampling, so absence is guaranteed.
    target = 9998
    nums = sorted(rng.sample(range(-9999, target), n))
    if present:
        target = nums[-1]
    return {"nums": nums, "target": target}
