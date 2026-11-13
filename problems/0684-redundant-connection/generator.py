def chain(rng, n, shuffle=False):
    edges = [[i,i+1] for i in range(1,n)] + [[1,n]]
    if shuffle:
        rng.shuffle(edges)
    return {"edges":edges}

def star(rng, n):
    edges = [[1,i] for i in range(2,n+1)] + [[n-1,n]]
    rng.shuffle(edges)
    return {"edges":edges}
