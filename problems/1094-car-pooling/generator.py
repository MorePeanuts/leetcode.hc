def full_route(rng, n, passengers, capacity):
    return {"trips": [[passengers, 0, 1000] for _ in range(n)], "capacity": capacity}

def staggered(rng, n):
    return {"trips": [[100, i % 100, 1000 - i % 100] for i in range(n)], "capacity": 100000}
