def mirrored(rng, n, shape, break_value=False, extra=False):
    nodes = [[rng.randint(-100, 100), None, None] for _ in range(n)]
    for i, node in enumerate(nodes):
        if shape == "chain":
            if i + 1 < n:
                node[1] = nodes[i + 1]
        else:
            if 2 * i + 1 < n:
                node[1] = nodes[2 * i + 1]
            if 2 * i + 2 < n:
                node[2] = nodes[2 * i + 2]
    def mirror(node):
        if node is None:
            return None
        return [node[0], mirror(node[2]), mirror(node[1])]
    root = [0, nodes[0], mirror(nodes[0])]
    if break_value:
        nodes[-1][0] = (nodes[-1][0] + 101) % 201 - 100
    if extra:
        nodes[-1][1] = [1, None, None]
    values = []
    queue = [root]
    for node in queue:
        if node is None:
            values.append(None)
        else:
            values.append(node[0])
            queue.extend(node[1:])
    while values[-1] is None:
        values.pop()
    return {"root": values}


def chain(rng, n):
    values = [0]
    for _ in range(n - 1):
        values.extend([None, rng.randint(-100, 100)])
    return {"root": values}
