# Lists of up to 10^4 nodes, values in [-10^5, 10^5]; pos is -1 (no cycle)
# or the index the tail links back to.


def random_list(rng, n, pos):
    # n random values; pos -1 for no cycle, or the index the tail links to.
    return {"head": [rng.randint(-10**5, 10**5) for _ in range(n)], "pos": pos}


def equal_values(rng, n, pos):
    # n nodes of the same value: a solution that remembers values instead of
    # nodes sees a repeat at once.
    return {"head": [7] * n, "pos": pos}
