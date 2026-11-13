def slopes(rng, n, mode):
    if mode == 0:
        nums = list(range(n))
    elif mode == 1:
        nums = list(range(n, 0, -1))
    else:
        nums = [i % 2 for i in range(n)]
    return {"nums": nums}
