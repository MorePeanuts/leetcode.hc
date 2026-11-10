# BSTs of 2 to 10^5 nodes with unique values in [-10^9, 10^9], and two
# distinct nodes p and q, given by their values. A tree's shape is built as
# parallel lists (left child, right child; -1 for none) with node 0 the
# root; its values are distinct random values assigned in in-order, which
# makes any shape a BST.

LIMIT = 10**9


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


def _bst_values(rng, left, right):
    n = len(left)
    sorted_vals = sorted(rng.sample(range(-LIMIT, LIMIT + 1), n))
    vals = [0] * n
    stack, node, k = [], 0, 0
    while stack or node >= 0:
        while node >= 0:
            stack.append(node)
            node = left[node]
        node = stack.pop()
        vals[node] = sorted_vals[k]
        k += 1
        node = right[node]
    return vals


def _parents_depths(left, right):
    n = len(left)
    parent, depth = [-1] * n, [0] * n
    order = [0]
    for x in order:
        for c in (left[x], right[x]):
            if c >= 0:
                parent[c] = x
                depth[c] = depth[x] + 1
                order.append(c)
    return parent, depth, order


def _case(rng, left, right, pick):
    # pick: "deepest" (the deepest node and its parent, the answer at the
    # bottom), "root" (the root and the deepest node), "leaves" (two random
    # leaves), "random" (two random nodes).
    vals = _bst_values(rng, left, right)
    parent, depth, order = _parents_depths(left, right)
    n = len(left)
    if pick == "deepest":
        a = order[-1]
        b = parent[a]
    elif pick == "root":
        a, b = 0, order[-1]
    elif pick == "leaves":
        leaves = [x for x in range(n) if left[x] < 0 and right[x] < 0]
        if len(leaves) < 2:
            raise ValueError("fewer than two leaves")
        a, b = rng.sample(leaves, 2)
    elif pick == "random":
        a, b = rng.sample(range(n), 2)
    else:
        raise ValueError(pick)
    if rng.random() < 0.5:
        a, b = b, a
    return {"root": _level_order(vals, left, right), "p": vals[a], "q": vals[b]}


def chain(rng, n, shape, pick):
    # A path of n nodes: "left" or "right" skewed, or "zigzag", turning at
    # every node.
    left, right = [-1] * n, [-1] * n
    for i in range(n - 1):
        side = shape if shape != "zigzag" else ("left" if i % 2 == 0 else "right")
        (left if side == "left" else right)[i] = i + 1
    return _case(rng, left, right, pick)


def balanced(rng, n, pick):
    # The complete tree of n nodes.
    left = [2 * i + 1 if 2 * i + 1 < n else -1 for i in range(n)]
    right = [2 * i + 2 if 2 * i + 2 < n else -1 for i in range(n)]
    return _case(rng, left, right, pick)


def random_shape(rng, n, pick):
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
    return _case(rng, left, right, pick)


def broom(rng, n, handle, pick):
    # A zigzag path of `handle` nodes from the root, whose last node splits
    # into a left-skewed and a right-skewed arm: with "leaves", p and q are
    # the ends of the two arms and the answer is deep down.
    left, right = [-1] * n, [-1] * n
    for i in range(handle - 1):
        (left if i % 2 == 0 else right)[i] = i + 1
    rest = n - handle
    half = rest // 2
    prev = handle - 1
    for i in range(handle, handle + half):
        left[prev] = i
        prev = i
    prev = handle - 1
    for i in range(handle + half, n):
        right[prev] = i
        prev = i
    return _case(rng, left, right, pick)
