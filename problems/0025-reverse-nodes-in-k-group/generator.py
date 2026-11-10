# Lists of up to 5000 nodes, values in [0, 1000], and 1 <= k <= n.


def random_list(rng, n, k):
    return {"head": [rng.randint(0, 1000) for _ in range(n)], "k": k}


def positions(rng, n, k):
    # Values 0, 1, ... wrapping after 1000: the output shows where each node
    # went.
    return {"head": [i % 1001 for i in range(n)], "k": k}
