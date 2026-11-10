# Inputs for leastInterval: 1 <= len(tasks) <= 10^4 uppercase letters and
# 0 <= n <= 100.

LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"


def random_tasks(rng, m, letters, n):
    # m tasks drawn at random from the first letters letters.
    return {"tasks": [rng.choice(LETTERS[:letters]) for _ in range(m)], "n": n}


def one_task(rng, m, n):
    # m copies of one task: (m - 1) * (n + 1) + 1 intervals, mostly idle.
    return {"tasks": ["Q"] * m, "n": n}


def equal_counts(rng, m, letters, n):
    # m tasks, the first letters letters as evenly as possible, shuffled.
    tasks = [LETTERS[i % letters] for i in range(m)]
    rng.shuffle(tasks)
    return {"tasks": tasks, "n": n}


def dominant(rng, m, share, n):
    # A share (in percent) of the m tasks is one letter, the rest random
    # among the other 25.
    top = m * share // 100
    tasks = ["Z"] * top + [rng.choice(LETTERS[:25]) for _ in range(m - top)]
    rng.shuffle(tasks)
    return {"tasks": tasks, "n": n}
