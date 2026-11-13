def large(rng, n, spread=False):
    nums = sorted(rng.sample(range(-10000, 10001), n)) if spread else list(range(-n//2, -n//2+n))
    return {"nums": nums}
