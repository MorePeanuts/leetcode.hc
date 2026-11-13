def full_range(rng, n, order):
    nums = list(range(1, n + 1))
    if order == "reverse":
        nums.reverse()
    elif order == "shuffle":
        rng.shuffle(nums)
    return {"nums": nums}
