MAX_COIN = 2**31 - 1


def random_coins(rng, k, lo, hi, amount):
    # k distinct denominations in [lo, hi].
    return {"coins": rng.sample(range(lo, hi + 1), k), "amount": amount}


def unreachable(rng, k, lo, amount):
    # Only even denominations and an odd amount: no combination works, so a
    # search must exhaust every one.
    coins = [2 * x for x in rng.sample(range(lo, lo + 4 * k), k)]
    return {"coins": coins, "amount": amount | 1}


def ones(rng, amount):
    # Only the coin 1: the answer is amount itself.
    return {"coins": [1], "amount": amount}


def greedy_trap(rng, amount):
    # Denominations where taking the largest coin first is not optimal.
    return {"coins": [1, 3, 4, 997, 1000, 2**31 - 1], "amount": amount}


def with_huge(rng, k, amount):
    # Small denominations mixed with values near 2^31 - 1 that never fit.
    small = rng.sample(range(7, 300), k // 2)
    huge = rng.sample(range(MAX_COIN - 10**6, MAX_COIN + 1), k - k // 2)
    coins = small + huge
    rng.shuffle(coins)
    return {"coins": coins, "amount": amount}
