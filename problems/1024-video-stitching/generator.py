def unit_chain(rng, n):
    clips = [[i, i + 1] for i in range(n)]
    rng.shuffle(clips)
    return {"clips": clips, "time": n}


def broken_chain(rng, n):
    clips = [[i, i + 1] for i in range(n)]
    clips[-2] = [n - 2, n - 2]
    rng.shuffle(clips)
    return {"clips": clips, "time": n}


def overlapping(rng, n):
    clips = [[0, 3], [97, 100]]
    for _ in range(n - 2):
        start = rng.randint(0, 97)
        clips.append([start, min(100, start + rng.randint(0, 12))])
    rng.shuffle(clips)
    return {"clips": clips, "time": 100}
