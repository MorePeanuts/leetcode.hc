def traversal(rng, n, mode):
    if mode == "wide":
        nested = [[i, [], [i + 1], []] for i in range(n)]
    elif mode == "empty":
        nested = [[[], [[]], []] for _ in range(n)]
    elif mode == "deep":
        value = 1000000
        for _ in range(n):
            value = [[], value, []]
        nested = [value, -1000000]
    else:
        nested = [rng.randint(-1000000, 1000000) for _ in range(n)]
    flat = []
    stack = list(reversed(nested))
    while stack:
        value = stack.pop()
        if isinstance(value, int):
            flat.append(value)
        else:
            stack.extend(reversed(value))
    ops = ["NestedIterator"]
    args = [[nested]]
    for _ in flat:
        ops.extend(["hasNext", "hasNext", "next"])
        args.extend([[], [], []])
    ops.extend(["hasNext", "hasNext"])
    args.extend([[], []])
    return {"ops": ops, "args": args}
