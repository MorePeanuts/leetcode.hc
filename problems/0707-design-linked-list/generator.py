def _case(calls):
    return {
        "ops": ["MyLinkedList"] + [op for op, _ in calls],
        "args": [[]] + [args for _, args in calls],
    }


def grow_and_read(rng, n, at_head=False):
    """Grow beyond the maximum query index, then read boundary positions."""
    op = "addAtHead" if at_head else "addAtTail"
    calls = [(op, [i % 1001]) for i in range(n - 10)]
    calls += [("get", [i]) for i in [0, 1, 499, 500, 999, 1000, 0, 1000, 1, 999]]
    return _case(calls)


def drain_and_refill(rng, n):
    """Repeatedly remove the tail, empty the list, and reuse its endpoints."""
    calls = []
    while len(calls) + 200 <= n:
        calls += [("addAtTail", [i * 10]) for i in range(50)]
        for i in range(49, -1, -1):
            calls += [("get", [i]), ("deleteAtIndex", [i]), ("get", [i])]
    calls += [("get", [0])] * (n - len(calls))
    return _case(calls)


def indexed_edits(rng, n):
    """Insert and delete in the middle of a long list, checking both neighbors."""
    calls = [("addAtTail", [i]) for i in range(1000)]
    while len(calls) + 5 <= n:
        calls += [
            ("addAtIndex", [500, 1000]),
            ("get", [500]),
            ("get", [501]),
            ("deleteAtIndex", [500]),
            ("get", [500]),
        ]
    calls += [("get", [1000])] * (n - len(calls))
    return _case(calls)


def mixed(rng, n):
    """Seeded operations biased toward valid indices and length boundaries."""
    calls = []
    size = 0
    for _ in range(n - 1):
        op = rng.choice(["get", "addAtHead", "addAtTail", "addAtIndex", "deleteAtIndex"])
        index = rng.choice([0, min(size, 1000), min(size + 1, 1000),
                            max(0, min(size - 1, 1000)), rng.randint(0, min(size, 1000))])
        val = rng.choice([0, 1000, rng.randint(0, 1000)])
        if op in ("addAtHead", "addAtTail"):
            args = [val]
            size += 1
        elif op == "addAtIndex":
            args = [index, val]
            size += int(index <= size)
        else:
            args = [index]
            if op == "deleteAtIndex" and index < size:
                size -= 1
        calls.append((op, args))
    calls.append(("get", [min(size, 1000)]))
    return _case(calls)
