def oscillating(rng, n):
    return {"prices": [0 if i % 3 != 1 else 1000 for i in range(n)]}
def varied(rng, n):
    return {"prices": [rng.randint(0, 1000) for _ in range(n)]}
