# Binary trees of at most 5000 nodes, values in [-10^4, 10^4]. A tree is
# built as parallel lists (left child, right child; -1 for none) with node 0
# the root, and written in level order.


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
    return [rng.randint(-10**4, 10**4) for _ in range(n)]


def chain(rng, n, shape):
    # A path of n nodes: "left" or "right" skewed, or "zigzag", turning at
    # every node. Unbalanced from the root down.
    left, right = [-1] * n, [-1] * n
    for i in range(n - 1):
        side = shape if shape != "zigzag" else ("left" if i % 2 == 0 else "right")
        (left if side == "left" else right)[i] = i + 1
    return _level_order(_values(rng, n), left, right)


def two_chains(rng, n):
    # A root with a left-skewed and a right-skewed arm of equal length: the
    # root is balanced, the nodes below it are not.
    left, right = [-1] * n, [-1] * n
    half = (n - 1) // 2
    prev = 0
    for i in range(1, half + 1):
        left[prev] = i
        prev = i
    prev = 0
    for i in range(half + 1, 2 * half + 1):
        right[prev] = i
        prev = i
    m = 2 * half + 1
    return _level_order(_values(rng, m), left[:m], right[:m])


def complete(rng, n, extra):
    # A complete tree of n - extra nodes; with extra = 2, its last node gets
    # a left child that gets a left child of its own: that node and the
    # nodes on its path to the root are unbalanced.
    base = n - extra
    left = [2 * i + 1 if 2 * i + 1 < base else -1 for i in range(n)]
    right = [2 * i + 2 if 2 * i + 2 < base else -1 for i in range(n)]
    prev = base - 1
    for i in range(base, n):
        left[prev] = i
        prev = i
    return _level_order(_values(rng, n), left, right)


def fibonacci(rng, height, mirror, defect):
    # The smallest balanced tree of the given height: every node's left
    # subtree is one level higher than its right one (with mirror, the
    # right one is higher), so the leaves' depths differ by up to half the
    # height. With defect, the node of height 3 at the end of the path that
    # follows the higher side loses its lower subtree, a single leaf: it is
    # the only unbalanced node (subtrees of heights 2 and 0), and every
    # height above it stays the same.
    left, right = [], []

    def build(h):
        # iterative: a stack of (height, parent, side) to place
        root = None
        stack = [(h, -1, 0)]
        while stack:
            hh, parent, side = stack.pop()
            if hh <= 0:
                continue
            idx = len(left)
            left.append(-1)
            right.append(-1)
            if parent < 0:
                root = idx
            elif side == 0:
                left[parent] = idx
            else:
                right[parent] = idx
            hi, lo = hh - 1, hh - 2
            if mirror:
                stack.append((lo, idx, 0))
                stack.append((hi, idx, 1))
            else:
                stack.append((hi, idx, 0))
                stack.append((lo, idx, 1))
        return root

    build(height)
    n = len(left)
    if defect:
        # Follow the higher side from the root down to the node of height 3,
        # and remove its lower subtree (height 1, a single leaf): that node
        # then has subtrees of heights 2 and 0.
        node, h = 0, height
        while h > 3:
            node = right[node] if mirror else left[node]
            h -= 1
        if mirror:
            left[node] = -1
        else:
            right[node] = -1
    return _level_order(_values(rng, n), left, right)
