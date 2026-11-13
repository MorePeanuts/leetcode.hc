def duplicate_pivot(rng, n, mode):
    nums = [1]*n
    if mode < 2:
        nums[n//3 if mode == 0 else n-2] = 0
    return {"nums": nums, "target": 0}
