def long_path(rng, n, mode):
    if mode == 0:
        path = "/" + "a"*(n-1)
    elif mode == 1:
        path = "/a/.."*(n//5)
    else:
        path = "/../"*(n//4)
    return {"path": path}
