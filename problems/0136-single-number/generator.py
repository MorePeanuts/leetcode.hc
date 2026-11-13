def paired(rng, n, singleton, layout):
    # n is odd; every selected value is distinct and excludes singleton.
    population = list(range(-30000, singleton)) + list(range(singleton + 1, 30001))
    values = rng.sample(population, (n - 1) // 2)
    if layout == "adjacent":
        nums = [value for value in values for _ in range(2)]
    else:
        nums = values + values[::-1]
        if layout == "shuffled":
            rng.shuffle(nums)
    nums.append(singleton)
    return {"nums": nums}
