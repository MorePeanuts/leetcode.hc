# Binary trees of at most 10^4 nodes, values in [-2^31, 2^31 - 1]. A tree is
# built as parallel lists (value, left child, right child; -1 for none) with
# node 0 the root, and written in level order.

MIN, MAX = -2**31, 2**31 - 1


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


def _chain(vals, sides):
    # A path: node i + 1 is the child of node i on side sides[i].
    n = len(vals)
    left, right = [-1] * n, [-1] * n
    for i in range(n - 1):
        (left if sides[i] == "L" else right)[i] = i + 1
    return _level_order(vals, left, right)


def right_chain(rng, n, broken):
    # Ascending values down a right-skewed path: a valid BST. With broken,
    # the deepest node is instead the left child of its parent, smaller than
    # its parent but also smaller than the root: only checking each node
    # against its parent misses it.
    vals = [MAX - n + 1 + i for i in range(n)]
    sides = ["R"] * (n - 1)
    if broken:
        sides[-1] = "L"
        vals[-1] = vals[0] - 1
    return _chain(vals, sides)


def left_chain(rng, n):
    # Descending values down a left-skewed path from 2^31 - 1: a valid BST
    # whose smallest value is -2^31 when n is large enough to reach it.
    vals = [MAX - i * ((2**32 - 1) // max(n - 1, 1)) for i in range(n)]
    vals[-1] = MIN if n > 1 else vals[-1]
    return _chain(vals, "L" * (n - 1))


def zigzag(rng, n):
    # A path that turns at every node, its values closing in from both
    # sides: valid, and every node bounded by two ancestors.
    vals, sides = [], []
    lo, hi = -n, n
    for i in range(n):
        if i % 2 == 0:
            vals.append(hi)
            hi -= 1
            sides.append("L")
        else:
            vals.append(lo)
            lo += 1
            sides.append("R")
    return _chain(vals, sides)


def complete(rng, n, gap, dup):
    # A complete tree labeled in order with step gap: a valid BST of
    # minimum height. With dup, the largest value repeats the one before it
    # in order: equal values make it invalid.
    left = [2 * i + 1 if 2 * i + 1 < n else -1 for i in range(n)]
    right = [2 * i + 2 if 2 * i + 2 < n else -1 for i in range(n)]
    vals = [0] * n
    order = []
    stack, node = [], 0
    while stack or node >= 0:
        while node >= 0:
            stack.append(node)
            node = left[node]
        node = stack.pop()
        vals[node] = MIN + len(order) * gap
        order.append(node)
        node = right[node]
    if dup:
        vals[order[-1]] = vals[order[-2]]
    return _level_order(vals, left, right)


def random_bst(rng, n, swap):
    # A BST built by inserting n distinct random values. With swap, the
    # values of two random nodes are exchanged afterwards: no longer a BST.
    vals = rng.sample(range(MIN, MAX + 1), n)
    left, right = [-1] * n, [-1] * n
    for i in range(1, n):
        cur = 0
        while True:
            side = left if vals[i] < vals[cur] else right
            if side[cur] < 0:
                side[cur] = i
                break
            cur = side[cur]
    if swap:
        a, b = rng.sample(range(n), 2)
        vals[a], vals[b] = vals[b], vals[a]
    return _level_order(vals, left, right)
