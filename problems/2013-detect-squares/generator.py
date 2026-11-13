def dense_queries(rng, n):
    ops = ["DetectSquares"]
    args = [[]]
    points = [[x, y] for x in range(40) for y in range(40)]
    rng.shuffle(points)
    for point in points:
        ops.append("add")
        args.append([point])
    for i in range(n - len(points)):
        ops.append("count")
        args.append([[i % 40, (i * 17) % 40]])
    return {"ops": ops, "args": args}

def multiplicity(rng, n):
    ops = ["DetectSquares"]
    args = [[]]
    points = [[0, 1000], [1000, 0], [1000, 1000]]
    for i in range(n - 1):
        ops.append("add")
        args.append([points[i % 3]])
    ops.append("count")
    args.append([[0, 0]])
    return {"ops": ops, "args": args}
