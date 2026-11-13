def quotes(rng, n, shape):
    if shape == "increasing":
        prices = list(range(1, n + 1))
    elif shape == "equal":
        prices = [100000] * n
    elif shape == "plateaus":
        prices = [i // 10 + 1 for i in range(n)]
    else:
        prices = list(range(n, 0, -1))
    return {"ops": ["StockSpanner"] + ["next"] * n, "args": [[]] + [[p] for p in prices]}
