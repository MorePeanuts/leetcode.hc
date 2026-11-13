from collections import deque

def large(rng, n, shape="balanced", position="middle"):
    values = list(range(1, 2*n, 2))
    root = []
    if shape == "balanced":
        q = deque([(0, n)])
        while q:
            lo, hi = q.popleft()
            if lo == hi: root.append(None); continue
            mid = (lo+hi)//2
            root.append(values[mid])
            q.extend([(lo, mid), (mid+1, hi)])
    else:
        if shape == "left": values.reverse()
        root = [values[0]]
        for value in values[1:]:
            root.extend([value, None] if shape == "left" else [None, value])
    while root and root[-1] is None: root.pop()
    val = 0 if position == "low" else 2*n if position == "high" else 2*(n//2)
    return {"root": root, "val": val}
