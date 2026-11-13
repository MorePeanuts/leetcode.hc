def late_start(rng, n, amount):
    gas, cost = [0] * n, [0] * n
    gas[-1] = amount
    cost[-2] = amount
    return {"gas": gas, "cost": cost}
def impossible(rng, n):
    return {"gas": [0] * n, "cost": [0] * (n - 1) + [1]}
def unique_rotated(rng, n, start):
    gas, cost = [10000] * n, [10000] * n
    cost[start] = 9999
    gas[(start - 1) % n] = 9999
    return {"gas": gas, "cost": cost}
