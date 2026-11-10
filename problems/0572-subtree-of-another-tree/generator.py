# root has at most 2000 nodes and subRoot at most 1000, values in
# [-10^4, 10^4]. A tree is built as parallel lists (value, left child, right
# child; -1 for none) with node 0 the root, and written in level order.


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
    return out


def _chain(vals, shape):
    n = len(vals)
    left, right = [-1] * n, [-1] * n
    for i in range(n - 1):
        side = shape if shape != "zigzag" else ("left" if i % 2 == 0 else "right")
        (left if side == "left" else right)[i] = i + 1
    return _level_order(vals, left, right)


def _random_shape(rng, n):
    left, right = [-1] * n, [-1] * n
    slots = [(0, 0), (0, 1)]
    for i in range(1, n):
        j = rng.randint(0, len(slots) - 1)
        slots[j], slots[-1] = slots[-1], slots[j]
        parent, side = slots.pop()
        (left if side == 0 else right)[parent] = i
        slots.append((i, 0))
        slots.append((i, 1))
    return left, right


def chains(rng, n, m, root_shape, sub_shape, last):
    # root is a path of n nodes of value 7, subRoot a path of m nodes of
    # value 7 except its last, which is `last`. Every node of root starts a
    # match of up to m nodes: the worst case of comparing at every node.
    return {
        "root": _chain([7] * n, root_shape),
        "subRoot": _chain([7] * (m - 1) + [last], sub_shape),
    }


def complete(rng, n, m):
    # Complete trees of n and m nodes, all values 0: subRoot is a subtree of
    # root only when some node's subtree has exactly its shape.
    def tree(k):
        left = [2 * i + 1 if 2 * i + 1 < k else -1 for i in range(k)]
        right = [2 * i + 2 if 2 * i + 2 < k else -1 for i in range(k)]
        return _level_order([0] * k, left, right)

    return {"root": tree(n), "subRoot": tree(m)}


def embedded(rng, n, m, values, extra):
    # A random tree of n - m nodes with a copy of subRoot, a random tree of
    # m nodes, hung from a random free child slot; values in [0, values).
    # With extra, the copy's deepest node gets one more child, so the copy
    # is no longer a subtree of root (unless subRoot occurs elsewhere).
    base = n - m - (1 if extra else 0)
    sl, sr = _random_shape(rng, m)
    sv = [rng.randint(0, values - 1) for _ in range(m)]
    bl, br = _random_shape(rng, base)
    bv = [rng.randint(0, values - 1) for _ in range(base)]
    free = [(i, s) for i in range(base) for s, c in ((0, bl[i]), (1, br[i])) if c < 0]
    parent, side = rng.choice(free)
    vals = bv + sv
    left = bl + [c + base if c >= 0 else -1 for c in sl]
    right = br + [c + base if c >= 0 else -1 for c in sr]
    (left if side == 0 else right)[parent] = base
    if extra:
        # the deepest node of the copy, by a breadth-first walk
        queue = [base]
        for x in queue:
            for c in (left[x], right[x]):
                if c >= 0:
                    queue.append(c)
        deep = queue[-1]
        vals.append(rng.randint(0, values - 1))
        left.append(-1)
        right.append(-1)
        left[deep] = len(vals) - 1
    return {"root": _level_order(vals, left, right), "subRoot": _level_order(sv, sl, sr)}
