def chain(rng, n, mode="zero", left=False):
    if mode=="zero":values=[0]*n;target=0
    elif mode=="alternating":values=[1 if i%2 else -1 for i in range(n)];target=0
    elif mode=="positive":values=[1]*n;target=n
    else:values=[1000000000]*n;target=0
    root=[values[0]]
    for value in values[1:]:root.extend([value,None] if left else [None,value])
    while root and root[-1] is None:root.pop()
    return {"root":root,"targetSum":target}

def branching(rng, n):
    return {"root":[rng.randint(-3,3) for _ in range(n)],"targetSum":0}
