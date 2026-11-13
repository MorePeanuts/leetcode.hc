from collections import deque

def large(rng, n, shape="balanced", target="root"):
    values = list(range(1, n+1))
    if shape == "balanced":
        root = []
        q=deque([(0,n)])
        while q:
            lo,hi=q.popleft()
            if lo==hi: root.append(None);continue
            mid=(lo+hi)//2
            root.append(values[mid])
            q.extend([(lo,mid),(mid+1,hi)])
    else:
        if shape=="left":values.reverse()
        root=[values[0]]
        for v in values[1:]:root.extend([v,None] if shape=="left" else [None,v])
    while root and root[-1] is None:root.pop()
    key=root[0] if target=="root" else values[-1] if target=="deep" else n+1
    return {"root":root,"key":key}
