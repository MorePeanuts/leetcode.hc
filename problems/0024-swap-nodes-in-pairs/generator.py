def ascending(rng, n):
    return {"head": list(range(n))}

def alternating(rng, n):
    return {"head": [0 if i % 2 == 0 else 100 for i in range(n)]}
