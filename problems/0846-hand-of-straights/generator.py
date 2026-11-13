def consecutive(rng, n, group_size):
    hand = list(range(n))
    rng.shuffle(hand)
    return {"hand": hand, "groupSize": group_size}
def repeated(rng, n, group_size):
    hand = [i % group_size for i in range(n)]
    rng.shuffle(hand)
    return {"hand": hand, "groupSize": group_size}
def late_gap(rng, n, group_size):
    hand = list(range(n - 1)) + [1000000000]
    rng.shuffle(hand)
    return {"hand": hand, "groupSize": group_size}
