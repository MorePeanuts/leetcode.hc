def delayed(rng, n, possible):
    triplets = [[1, 1, 1] for _ in range(n - 3)]
    triplets += [[1000, 1, 1], [1, 1000, 1], [1, 1, 1000 if possible else 999]]
    return {"triplets": triplets, "target": [1000, 1000, 1000]}
def polluted(rng, n):
    triplets = [[1000, 500, 500] for _ in range(n - 3)]
    triplets += [[500, 1, 1], [1, 500, 1], [1, 1, 500]]
    return {"triplets": triplets, "target": [500, 500, 500]}
