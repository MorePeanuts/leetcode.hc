def full_ranges(rng, n, count, seats):
    return {"bookings": [[1, n, seats] for _ in range(count)], "n": n}

def broad_ranges(rng, n, count):
    return {"bookings": [[1 + i % 100, n - i % 100, 1 + i % 10000] for i in range(count)], "n": n}
