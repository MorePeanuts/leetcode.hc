# Binary trees of at most 3 * 10^4 nodes, values in [-1000, 1000]. A tree is
# built as parallel lists (value, left child, right child; -1 for none) with
# node 0 the root, and written in level order.


def _values(rng, n, kind):
    if kind == "random":
        return [rng.randint(-1000, 1000) for _ in range(n)]
    if kind == "negative":
        return [rng.randint(-1000, -1) for _ in range(n)]
    if kind == "max":
        return [1000] * n
    if kind == "min":
        return [-1000] * n
    raise ValueError(kind)


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


def chain(rng, n, shape, values):
    # A path of n nodes: "right" or "left" skewed, or "zigzag", turning at
    # every node.
    vals = _values(rng, n, values)
    left, right = [-1] * n, [-1] * n
    for i in range(n - 1):
        side = shape if shape != "zigzag" else ("left" if i % 2 == 0 else "right")
        (left if side == "left" else right)[i] = i + 1
    return _level_order(vals, left, right)


def two_arms(rng, n, values):
    # A root with a left-skewed and a right-skewed arm of (n - 1) / 2 nodes
    # each: the best path runs down both arms.
    vals = _values(rng, n, values)
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
    return _level_order(vals, left, right)


def complete(rng, n, values):
    vals = _values(rng, n, values)
    left = [2 * i + 1 if 2 * i + 1 < n else -1 for i in range(n)]
    right = [2 * i + 2 if 2 * i + 2 < n else -1 for i in range(n)]
    return _level_order(vals, left, right)


def random_shape(rng, n, values):
    # Each node after the root takes a random free child slot of the nodes
    # placed so far.
    vals = _values(rng, n, values)
    left, right = [-1] * n, [-1] * n
    slots = [(0, 0), (0, 1)]
    for i in range(1, n):
        j = rng.randint(0, len(slots) - 1)
        slots[j], slots[-1] = slots[-1], slots[j]
        parent, side = slots.pop()
        (left if side == 0 else right)[parent] = i
        slots.append((i, 0))
        slots.append((i, 1))
    return _level_order(vals, left, right)


def caterpillar(rng, n):
    # A right-skewed spine of negative values with a leaf of 1000 hanging
    # left of every spine node: the best path joins two leaves through the
    # spine, never along it.
    spine = n // 2
    vals, left, right = [], [], []
    for i in range(spine):
        vals.append(-rng.randint(1, 1000))
        left.append(-1)
        right.append(-1)
    for i in range(spine):
        if len(vals) >= n:
            break
        left[i] = len(vals)
        vals.append(1000)
        left.append(-1)
        right.append(-1)
    for i in range(spine - 1):
        right[i] = i + 1
    return _level_order(vals, left, right)
