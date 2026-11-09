# Lists of up to 1000 nodes, values in [-10^4, 10^4], each random pointer
# null or the index of a node of the list.


def random_list(rng, n, nulls):
    # n random values; each random pointer is null with probability nulls
    # percent, otherwise a random node.
    head = []
    for _ in range(n):
        r = None if rng.randint(1, 100) <= nulls else rng.randint(0, n - 1)
        head.append([rng.randint(-10**4, 10**4), r])
    return {"head": head}


def equal_values(rng, n):
    # n nodes of one value with random pointers: only the nodes' positions
    # tell the pointers apart.
    return {"head": [[5, rng.randint(0, n - 1)] for _ in range(n)]}
