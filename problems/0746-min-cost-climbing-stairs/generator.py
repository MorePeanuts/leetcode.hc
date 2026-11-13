def alternating(rng, n):
    return {"cost": [1 if i % 3 else 999 for i in range(n)]}
def varied(rng, n):
    return {"cost": [rng.randint(0,999) for _ in range(n)]}
