def shuffled(rng, values):
    nums = values.copy()
    rng.shuffle(nums)
    return {"nums": nums}
