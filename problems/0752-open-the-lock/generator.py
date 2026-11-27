def scattered(rng, count, target):
    candidates = [code for code in range(1, 10000) if code != int(target)]
    deadends = [f"{code:04d}" for code in rng.sample(candidates, count)]
    return {"deadends": deadends, "target": target}
