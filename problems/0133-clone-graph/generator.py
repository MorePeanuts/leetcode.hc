def connected(rng, n, dense=False):
    adj = [set() for _ in range(n)]
    for i in range(1, n):
        j = rng.randint(0, i - 1)
        adj[i].add(j + 1)
        adj[j].add(i + 1)
    for i in range(n):
        for j in range(i + 1, n):
            if dense or rng.randint(0, 4) == 0:
                adj[i].add(j + 1)
                adj[j].add(i + 1)
    result = [sorted(row) for row in adj]
    for row in result:
        rng.shuffle(row)
    return {"node": result}
