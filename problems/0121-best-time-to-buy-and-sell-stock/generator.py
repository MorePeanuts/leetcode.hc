TOP = 10**4


def random_prices(rng, n, top=TOP):
    return {"prices": [rng.randint(0, top) for _ in range(n)]}


def descending(rng, n):
    # Never rising: the answer is 0.
    return {"prices": [TOP - i * TOP // (n - 1) for i in range(n)]}


def ascending(rng, n):
    # Buy on the first day, sell on the last: the largest answer.
    return {"prices": [i * TOP // (n - 1) for i in range(n)]}


def all_equal(rng, n):
    return {"prices": [rng.randint(0, TOP)] * n}


def low_after_high(rng, n):
    # Random prices with the maximum near the start and the minimum near the
    # end, so the global minimum and maximum make no valid trade.
    prices = [rng.randint(3000, 7000) for _ in range(n)]
    prices[rng.randint(0, 10)] = TOP
    prices[n - 1 - rng.randint(0, 10)] = 0
    return {"prices": prices}


def zigzag(rng, n):
    # Falling overall with small rises of 50, and one rise of 500 at a
    # random place in the second half.
    prices = []
    for i in range(n):
        base = TOP - i * (TOP - 100) // n
        prices.append(base - 50 if i % 2 == 0 else base)
    j = rng.randint(n // 2, n - 2)
    prices[j + 1] = min(TOP, prices[j] + 500)
    return {"prices": prices}
