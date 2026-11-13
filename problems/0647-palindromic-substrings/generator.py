def repeated(rng, n):
    return {"s": "a" * n}
def alternating(rng, n):
    return {"s": ("ab" * ((n+1)//2))[:n]}
def varied(rng, n):
    return {"s": "".join(rng.choice("abcd") for _ in range(n))}
