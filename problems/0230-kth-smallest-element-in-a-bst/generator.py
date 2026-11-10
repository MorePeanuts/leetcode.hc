# BSTs of 1 to 10^4 nodes with distinct values in [0, 10^4], and k in
# [1, n]. A tree's shape is built as parallel lists (left child, right
# child; -1 for none) with node 0 the root; its values are distinct random
# values assigned in in-order, which makes any shape a BST.

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
    return out


def _case(rng, left, right, k):
    # k: "first", "last", "middle", "random", or a number.
    n = len(left)
    sorted_vals = sorted(rng.sample(range(0, LIMIT + 1), n))
    vals = [0] * n
    stack, node, i = [], 0, 0
    while stack or node >= 0:
        while node >= 0:
            stack.append(node)
            node = left[node]
        node = stack.pop()
        vals[node] = sorted_vals[i]
        i += 1
        node = right[node]
    if k == "first":
        k = 1
    elif k == "last":
        k = n
    elif k == "middle":
        k = (n + 1) // 2
    elif k == "random":
        k = rng.randint(1, n)
    return {"root": _level_order(vals, left, right), "k": k}


def chain(rng, n, shape, k):
    # A path of n nodes: "left" or "right" skewed, or "zigzag", turning at
    # every node.
    left, right = [-1] * n, [-1] * n
    for i in range(n - 1):
        side = shape if shape != "zigzag" else ("left" if i % 2 == 0 else "right")
        (left if side == "left" else right)[i] = i + 1
    return _case(rng, left, right, k)


def balanced(rng, n, k):
    # The complete tree of n nodes.
    left = [2 * i + 1 if 2 * i + 1 < n else -1 for i in range(n)]
    right = [2 * i + 2 if 2 * i + 2 < n else -1 for i in range(n)]
    return _case(rng, left, right, k)


def random_shape(rng, n, k):
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
    return _case(rng, left, right, k)
