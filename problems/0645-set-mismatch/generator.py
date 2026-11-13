def mismatch(rng, n, missing, duplicate):
    nums = list(range(1, n + 1))
    nums[missing - 1] = duplicate
    rng.shuffle(nums)
    return {"nums": nums}
