def rotated(rng, n, k):
    # n distinct values of [-5000, 5000] in ascending order, rotated so that
    # the minimum is at index k (0: rotated n times, sorted as it was).
    values = sorted(rng.sample(range(-5000, 5001), n))
    k = k % n
    return {"nums": values[n - k:] + values[:n - k]}


def rotated_random(rng, n):
    # As rotated, the minimum at a random index.
    return rotated(rng, n, rng.randint(0, n - 1))
