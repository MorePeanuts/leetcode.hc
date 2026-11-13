def traversals(rng, n, shape):
    values = rng.sample(range(-3000, 3001), n)
    nodes = [[value, None, None] for value in values]
    if shape == "complete":
        for i, node in enumerate(nodes):
            if 2 * i + 1 < n:
                node[1] = nodes[2 * i + 1]
            if 2 * i + 2 < n:
                node[2] = nodes[2 * i + 2]
    elif shape == "random":
        slots = [(0, 1), (0, 2)]
        for i in range(1, n):
            pos = rng.randint(0, len(slots) - 1)
            parent, side = slots.pop(pos)
            nodes[parent][side] = nodes[i]
            slots.extend([(i, 1), (i, 2)])
    else:
        for i in range(n - 1):
            side = 2 if shape == "right" or shape == "alternating" and i % 2 else 1
            nodes[i][side] = nodes[i + 1]
    inorder = []
    postorder = []
    stack = [(nodes[0], 0)]
    while stack:
        node, state = stack.pop()
        if node is None:
            continue
        if state == 0:
            stack.extend([(node, 1), (node[1], 0)])
        elif state == 1:
            inorder.append(node[0])
            stack.extend([(node, 2), (node[2], 0)])
        else:
            postorder.append(node[0])
    return {"inorder": inorder, "postorder": postorder}
