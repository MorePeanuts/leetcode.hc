def scattered(rng, n):
    points = [[i * 1999 - 1000000, rng.randint(-1000000, 1000000)] for i in range(n)]
    rng.shuffle(points)
    return {'points': points}


def line(rng, n):
    points = [[i * 1999 - 1000000, 1000000] for i in range(n)]
    rng.shuffle(points)
    return {'points': points}
