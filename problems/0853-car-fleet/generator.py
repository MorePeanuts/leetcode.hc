# n cars with distinct positions in [0, target), speeds in [1, 10^6],
# target at most 10^6. The cars are listed in random order.


def _shuffled(rng, target, cars):
    rng.shuffle(cars)
    return {
        "target": target,
        "position": [p for p, _ in cars],
        "speed": [s for _, s in cars],
    }


def random_cars(rng, n, target, max_speed):
    # Random positions and speeds in [1, max_speed].
    position = rng.sample(range(target), n)
    cars = [(p, rng.randint(1, max_speed)) for p in position]
    return _shuffled(rng, target, cars)


def all_separate(rng, n, target):
    # The faster a car, the nearer the target it starts: each car arrives
    # strictly later than every car ahead of it, so no car catches up and
    # there are n fleets. A solution that looks for a car ahead to catch
    # looks at every one of them.
    position = sorted(rng.sample(range(target), n), reverse=True)
    speeds = sorted((rng.randint(1, 10**6) for _ in range(n)), reverse=True)
    return _shuffled(rng, target, list(zip(position, speeds)))


def same_time(rng, n, target):
    # Every car's speed is its distance to the target: all arrive at time 1
    # exactly, catching up at the target, one fleet. Solutions that count a
    # car arriving at the same time as a new fleet count n.
    position = rng.sample(range(target), n)
    return _shuffled(rng, target, [(p, target - p) for p in position])


def blocks(rng, n, target, k):
    # k fleets of about n / k cars each. Sorted from the target back, the
    # first car of a block (its lead) has speed 1, so it arrives at time
    # target - lead, later than every car ahead of it; every other car of
    # the block has a random speed fast enough to arrive no later than its
    # lead (some exactly at the same time), so it joins that fleet.
    position = sorted(rng.sample(range(target), n), reverse=True)
    size = (n + k - 1) // k
    cars = []
    for start in range(0, n, size):
        block = position[start:start + size]
        lead_dist = target - block[0]
        cars.append((block[0], 1))
        for p in block[1:]:
            dist = target - p
            least = (dist + lead_dist - 1) // lead_dist
            cars.append((p, least if rng.randint(0, 3) == 0 else rng.randint(least, 10**6)))
    return _shuffled(rng, target, cars)
