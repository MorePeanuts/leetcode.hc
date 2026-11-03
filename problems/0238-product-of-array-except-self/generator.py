def signs(rng, n, big, zeros):
    # Ones and minus ones, with `big` values of magnitude 2 or 3 and `zeros`
    # zeros at random places. Every product is at most 3^big in magnitude,
    # so big <= 19 keeps it within 32 bits.
    nums = [rng.choice((1, -1)) for _ in range(n)]
    places = rng.sample(range(n), big + zeros)
    for i in places[:big]:
        nums[i] = rng.choice((2, 3, -2, -3))
    for i in places[big:]:
        nums[i] = 0
    return {"nums": nums}


def scattered_twos(rng, n, count):
    # `count` minus twos at random places among ones: with count = 31 the
    # whole product is -2^31, the lowest 32-bit value.
    nums = [1] * n
    for i in rng.sample(range(n), count):
        nums[i] = -2
    return {"nums": nums}


def extremes_at_ends(rng, n):
    return {"nums": [30] + [1] * (n - 2) + [-30]}
