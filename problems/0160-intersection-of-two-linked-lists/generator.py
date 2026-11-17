def disjoint(rng, n):
    return {"headA": [1] * n, "headB": [1] * n, "skipA": n, "skipB": n}

def tail_join(rng, n, short):
    a = [1] * (n - 1) + [2]
    b = [1] * (short - 1) + [2]
    return {"headA": a, "headB": b, "skipA": n - 1, "skipB": short - 1}
