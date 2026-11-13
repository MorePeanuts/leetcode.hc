def tree(rng, n, shape, target_index, k):
    values = rng.sample(range(501), n)
    if shape == "complete":
        root = values
    else:
        root = [values[0]]
        for i, value in enumerate(values[1:], 1):
            right = shape == "right" or shape == "alternating" and i % 2 == 1
            root.extend([None, value] if right else [value, None])
        while root[-1] is None:
            root.pop()
    return {"root": root, "target": values[target_index], "k": k}
