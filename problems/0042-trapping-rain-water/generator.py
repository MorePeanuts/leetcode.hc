H = 10**5


def random_heights(rng, n, top=H):
    return {"height": [rng.randint(0, top) for _ in range(n)]}


def walls(rng, n):
    # The two ends at the maximum height, zeros between: the largest answer,
    # (n - 2) * 10^5.
    return {"height": [H] + [0] * (n - 2) + [H]}


def increasing(rng, n):
    return {"height": [i * H // (n - 1) for i in range(n)]}


def decreasing(rng, n):
    return {"height": [(n - 1 - i) * H // (n - 1) for i in range(n)]}


def mountain(rng, n):
    # Up to a peak in the middle and down again: no water.
    half = n // 2
    return {"height": [H - abs(i - half) * H // half for i in range(n)]}


def valley(rng, n):
    # Down to 0 in the middle and up again: water everywhere but the ends.
    half = n // 2
    return {"height": [abs(i - half) * H // half for i in range(n)]}


def sawtooth(rng, n, period):
    # Repeated teeth of random heights: many small pools.
    return {"height": [rng.randint(0, H) if i % period == 0 else rng.randint(0, 100) for i in range(n)]}


def peak_inside(rng, n):
    # Random low ground, one wall of 10^5 at a random place inside and lower
    # walls at the ends: each side fills to its own end wall.
    height = [rng.randint(0, 1000) for _ in range(n)]
    height[0] = rng.randint(5 * 10**4, H - 1)
    height[-1] = rng.randint(5 * 10**4, H - 1)
    height[rng.randint(1, n - 2)] = H
    return {"height": height}
