def alternating(rng, n):
    head = [rng.randint(0, 100) if i % 2 == 0 else rng.randint(-100, -1) for i in range(n)]
    return {"head": head, "x": 0}


def reversed_blocks(rng, n):
    head = [rng.randint(1, 100) for _ in range(n // 2)]
    head.extend(rng.randint(-100, 0) for _ in range(n - len(head)))
    return {"head": head, "x": 1}
