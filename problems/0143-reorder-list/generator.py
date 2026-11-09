# Lists of 1 to 5 * 10^4 nodes, values in [1, 1000]. Every list of the
# maximum length is the worst case of moving the tail forward one node at a
# time, which walks the remaining list for each node.


def random_list(rng, n):
    return {"head": [rng.randint(1, 1000) for _ in range(n)]}


def positions(rng, n):
    # Values 1, 2, ... wrapping at 1000: the order of the output shows where
    # each node went.
    return {"head": [i % 1000 + 1 for i in range(n)]}
