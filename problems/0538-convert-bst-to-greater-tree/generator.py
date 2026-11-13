from collections import deque

def large(rng, n, shape="balanced", offset=1):
    values=list(range(offset,offset+n))
    if shape=="balanced":
        root=[];q=deque([(0,n)])
        while q:
            lo,hi=q.popleft()
            if lo==hi:root.append(None);continue
            mid=(lo+hi)//2;root.append(values[mid]);q.extend([(lo,mid),(mid+1,hi)])
    else:
        if shape=="left":values.reverse()
        root=[values[0]]
        for v in values[1:]:root.extend([v,None] if shape=="left" else [None,v])
    while root and root[-1] is None:root.pop()
    return {"root":root}
