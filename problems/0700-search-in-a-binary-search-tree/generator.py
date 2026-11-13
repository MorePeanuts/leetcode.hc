from collections import deque

def chain(rng, n, left=False, absent=False):
    values = list(range(1, n+1))
    if left: values.reverse()
    root = [values[0]]
    for value in values[1:]:
        root.extend([value, None] if left else [None, value])
    while root[-1] is None: root.pop()
    return {"root": root, "val": n+1 if absent else values[-1]}

def balanced(rng, n, target=0):
    root = []
    q = deque([(1,n)])
    while q:
        lo, hi = q.popleft()
        if lo>hi: root.append(None); continue
        mid=(lo+hi)//2
        root.append(mid)
        q.extend([(lo,mid-1),(mid+1,hi)])
    while root[-1] is None:root.pop()
    return {"root":root,"val":target or (n+1)//2}
