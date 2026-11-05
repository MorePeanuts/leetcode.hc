def random_values(rng, n):
    # Distinct values over the whole range: about 10^4 triplets for n = 3000.
    return {"nums": rng.sample(range(-10**5, 10**5 + 1), n)}


def odd_values(rng, n):
    # Distinct odd values of both signs: three odd numbers never sum to 0, so
    # there is no triplet and nothing ends a search early.
    return {"nums": rng.sample(range(-99999, 10**5, 2), n)}

