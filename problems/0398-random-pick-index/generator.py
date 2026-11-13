def queries(rng, n, calls, mode):
    if mode == "same":
        nums = [-2147483648] * n
    elif mode == "sparse":
        nums = list(range(n))
        nums[0] = nums[n // 2] = nums[-1] = 2147483647
    elif mode == "mixed":
        nums = [(-2147483648, 0, 2147483647)[i % 3] for i in range(n)]
    else:
        nums = [rng.randint(-3, 3) for _ in range(n)]
    targets = [nums[0], nums[n // 2], nums[-1]]
    return {"ops": ["Solution"] + ["pick"] * calls,
            "args": [[nums]] + [[targets[i % 3]] for i in range(calls)]}
