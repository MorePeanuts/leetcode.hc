def uniform_batches(rng, n, size):
    ops = ["RandomizedSet"] + ["insert"] * size
    args = [[]] + [[i * 100003 - 1000000] for i in range(size)]
    for phase in range(3):
        ops.extend(["getRandom"] * n)
        args.extend([[] for _ in range(n)])
        old = phase * 100003 - 1000000
        new = 1000000000 + phase
        ops.extend(["remove", "insert", "insert", "remove"])
        args.extend([[old], [new], [new], [old]])
    return {"ops": ops, "args": args}


def churn(rng, n):
    # Large sets and repeated front removal expose linear scans/shifts.
    ops = ["RandomizedSet"] + ["insert"] * n
    args = [[]] + [[i] for i in range(n)]
    for i in range(n):
        ops.extend(["remove", "insert", "getRandom"])
        args.extend([[i], [n + i], []])
    return {"ops": ops, "args": args}
