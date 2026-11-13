def missing_value(rng, n, missing, layout):
    nums = [value for value in range(n + 1) if value != missing]
    if layout == "descending":
        nums.reverse()
    elif layout == "shuffled":
        rng.shuffle(nums)
    return {"nums": nums}
