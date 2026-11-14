def tree(rng, n, shape):
    children = [[] for _ in range(n)]
    for i in range(1, n):
        if shape == "star":
            parent = 0
        elif shape == "chain":
            parent = i - 1
        elif shape == "broom":
            parent = i - 1 if i < 999 else 998
        else:
            parent = (i - 1) // 4
        children[parent].append(i)
    values = [(i * 7919) % 10001 for i in range(n)]
    result = [values[0], None]
    queue = [0]
    for node in queue:
        result.extend(values[child] for child in children[node])
        result.append(None)
        queue.extend(children[node])
    while result[-1] is None:
        result.pop()
    return {"root": result}
