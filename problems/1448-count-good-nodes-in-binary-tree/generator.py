# Binary trees of 1 to 10^5 nodes, values in [-10^4, 10^4]. A tree is built
# as parallel lists (left child, right child; -1 for none) with node 0 the
# root, its values given in node order, and written in level order.

LIMIT = 10**4


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


def _values(rng, n, kind):
    # Values in node order, which on a path is the order from the root down:
    # "random"; "ascending" (every node good); "descending" (only the root
    # good); "equal" (every node good: equal values do not spoil it);
    # "sawtooth" (rising slowly with frequent dips, about half good).
    if kind == "random":
        return [rng.randint(-LIMIT, LIMIT) for _ in range(n)]
    if kind == "ascending":
        return [-LIMIT + (2 * LIMIT * i) // max(n - 1, 1) for i in range(n)]
    if kind == "descending":
        return [LIMIT - (2 * LIMIT * i) // max(n - 1, 1) for i in range(n)]
    if kind == "equal":
        return [rng.randint(-LIMIT, LIMIT)] * n
    if kind == "sawtooth":
        base = [-LIMIT + (2 * LIMIT * i) // max(n - 1, 1) for i in range(n)]
        return [b if rng.random() < 0.5 else max(-LIMIT, b - rng.randint(1, 100)) for b in base]
    raise ValueError(kind)


def chain(rng, n, shape, values):
    # A path of n nodes: "left" or "right" skewed, or "zigzag", turning at
    # every node.
    left, right = [-1] * n, [-1] * n
    for i in range(n - 1):
        side = shape if shape != "zigzag" else ("left" if i % 2 == 0 else "right")
        (left if side == "left" else right)[i] = i + 1
    return _level_order(_values(rng, n, values), left, right)


def two_arms(rng, n, values):
    # A root with a left-skewed and a right-skewed arm of (n - 1) / 2 nodes
    # each; values in node order, the left arm first.
    left, right = [-1] * n, [-1] * n
    half = (n - 1) // 2
    prev = 0
    for i in range(1, half + 1):
        left[prev] = i
        prev = i
    prev = 0
    for i in range(half + 1, n):
        right[prev] = i
        prev = i
    return _level_order(_values(rng, n, values), left, right)


def complete(rng, n, values):
    left = [2 * i + 1 if 2 * i + 1 < n else -1 for i in range(n)]
    right = [2 * i + 2 if 2 * i + 2 < n else -1 for i in range(n)]
    return _level_order(_values(rng, n, values), left, right)


def random_shape(rng, n, values):
    # Each node after the root takes a random free child slot of the nodes
    # placed so far, so that a node comes after its parent in node order.
    left, right = [-1] * n, [-1] * n
    slots = [(0, 0), (0, 1)]
    for i in range(1, n):
        j = rng.randint(0, len(slots) - 1)
        slots[j], slots[-1] = slots[-1], slots[j]
        parent, side = slots.pop()
        (left if side == 0 else right)[parent] = i
        slots.append((i, 0))
        slots.append((i, 1))
    return _level_order(_values(rng, n, values), left, right)
