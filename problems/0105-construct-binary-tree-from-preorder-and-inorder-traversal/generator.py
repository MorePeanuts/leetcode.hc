# Binary trees of 1 to 3000 nodes with unique values in [-3000, 3000],
# given by their preorder and inorder traversals. A tree's shape is built as
# parallel lists (left child, right child; -1 for none) with node 0 the
# root.

LIMIT = 3000


def _traversals(rng, left, right, values):
    # values: "random" (distinct random values), "sorted" (values ascending
    # in inorder: a BST, preorder alone would do), "reversed" (descending in
    # inorder).
    n = len(left)
    if values == "random":
        vals = rng.sample(range(-LIMIT, LIMIT + 1), n)
    else:
        inorder_vals = sorted(rng.sample(range(-LIMIT, LIMIT + 1), n))
        if values == "reversed":
            inorder_vals.reverse()
        vals = [0] * n
        stack, node, i = [], 0, 0
        while stack or node >= 0:
            while node >= 0:
                stack.append(node)
                node = left[node]
            node = stack.pop()
            vals[node] = inorder_vals[i]
            i += 1
            node = right[node]
    preorder, stack = [], [0]
    while stack:
        x = stack.pop()
        preorder.append(vals[x])
        if right[x] >= 0:
            stack.append(right[x])
        if left[x] >= 0:
            stack.append(left[x])
    inorder, stack, node = [], [], 0
    while stack or node >= 0:
        while node >= 0:
            stack.append(node)
            node = left[node]
        node = stack.pop()
        inorder.append(vals[node])
        node = right[node]
    return {"preorder": preorder, "inorder": inorder}


def chain(rng, n, shape, values):
    # A path of n nodes: "left" or "right" skewed, or "zigzag", turning at
    # every node.
    left, right = [-1] * n, [-1] * n
    for i in range(n - 1):
        side = shape if shape != "zigzag" else ("left" if i % 2 == 0 else "right")
        (left if side == "left" else right)[i] = i + 1
    return _traversals(rng, left, right, values)


def complete(rng, n, values):
    left = [2 * i + 1 if 2 * i + 1 < n else -1 for i in range(n)]
    right = [2 * i + 2 if 2 * i + 2 < n else -1 for i in range(n)]
    return _traversals(rng, left, right, values)


def random_shape(rng, n, values):
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
    return _traversals(rng, left, right, values)


def two_arms(rng, n, values):
    # A root with a left-skewed and a right-skewed arm of (n - 1) / 2 nodes.
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
    return _traversals(rng, left, right, values)
