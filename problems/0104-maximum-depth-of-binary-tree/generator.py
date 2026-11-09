# Binary trees of at most 10^4 nodes, values in [-100, 100]. A tree is built
# as parallel lists (left child, right child; -1 for none) with node 0 the
# root, and written in level order.


def _level_order(vals, left, right):
    out = [vals[0]]
    queue = [0]
    i = 0
    while i < len(queue):
        n = queue[i]
        i += 1
        for c in (left[n], right[n]):
            if c < 0:
                out.append(None)
            else:
                out.append(vals[c])
                queue.append(c)
    while out[-1] is None:
        out.pop()
    return {"root": out}


def _values(rng, n):
    return [rng.randint(-100, 100) for _ in range(n)]


def chain(rng, n, shape):
    # A path of n nodes, depth n: "left" or "right" skewed, or "zigzag",
    # turning at every node.
    left, right = [-1] * n, [-1] * n
    for i in range(n - 1):
        side = shape if shape != "zigzag" else ("left" if i % 2 == 0 else "right")
        (left if side == "left" else right)[i] = i + 1
    return _level_order(_values(rng, n), left, right)


def complete(rng, n):
    left = [2 * i + 1 if 2 * i + 1 < n else -1 for i in range(n)]
    right = [2 * i + 2 if 2 * i + 2 < n else -1 for i in range(n)]
    return _level_order(_values(rng, n), left, right)


def random_shape(rng, n):
    # Each node after the root takes a random free child slot of the nodes
    # placed so far.
    left, right = [-1] * n, [-1] * n
    slots = [(0, 0), (0, 1)]
    for i in range(1, n):
        j = rng.randint(0, len(slots) - 1)
        slots[j], slots[-1] = slots[-1], slots[j]
        parent, side = slots.pop()
        (left if side == 0 else right)[parent] = i
        slots.append((i, 0))
        slots.append((i, 1))
    return _level_order(_values(rng, n), left, right)


def comb(rng, n, depth):
    # A complete tree of n - depth + 1 nodes whose last node in level order
    # continues as a left-skewed path down to `depth` more levels: the deepest
    # leaf is the last one of a long, narrow branch.
    bushy = n - depth
    left = [2 * i + 1 if 2 * i + 1 < bushy else -1 for i in range(n)]
    right = [2 * i + 2 if 2 * i + 2 < bushy else -1 for i in range(n)]
    prev = bushy - 1
    for i in range(bushy, n):
        left[prev] = i
        prev = i
    return _level_order(_values(rng, n), left, right)
