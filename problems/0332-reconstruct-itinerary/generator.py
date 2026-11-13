def airport(i):
    return 'B' + chr(65 + i // 26) + chr(65 + i % 26)


def trapped_cycles(rng, n):
    edges = [['JFK', 'ZZZ'], ['ZZZ', 'JFK'], ['JFK', 'AAA']]
    for i in range((n - 3) // 2):
        name = airport(i)
        edges += [['AAA', name], [name, 'AAA']]
    if len(edges) < n:
        edges.append(['AAA', 'ZZY'])
    rng.shuffle(edges)
    return {'tickets': edges}


def repeated(rng, n):
    walk = ['JFK' if i % 2 == 0 else 'AAA' for i in range(n + 1)]
    edges = [list(pair) for pair in zip(walk, walk[1:])]
    rng.shuffle(edges)
    return {'tickets': edges}
