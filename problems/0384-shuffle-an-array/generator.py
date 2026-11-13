def operations(rng, n, calls, reset_every):
    nums = rng.sample(range(-1000000, 1000001), n)
    ops = ["Solution"]
    for i in range(calls):
        ops.append("reset" if reset_every and (i + 1) % reset_every == 0 else "shuffle")
    return {"ops": ops, "args": [[nums]] + [[] for _ in range(calls)]}
