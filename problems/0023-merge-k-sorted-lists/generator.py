# Inputs of k sorted lists: each at most 500 long, values in [-10^4, 10^4],
# at most 10^4 values in all.

LO, HI = -10**4, 10**4


def singletons(rng, k, order):
    # k lists of one value each. "ascending" puts them in increasing order,
    # the worst case of merging the lists one after another into the result;
    # "random" shuffles them.
    values = [LO + (HI - LO) * i // max(k - 1, 1) for i in range(k)]
    if order == "random":
        rng.shuffle(values)
    elif order == "descending":
        values.reverse()
    return {"lists": [[v] for v in values]}


def sorted_singletons(rng, k, lo, hi):
    # k lists of one random value in [lo, hi] each, in increasing order: the
    # worst case of merging the lists one after another, also with repeats.
    return {"lists": [[v] for v in sorted(rng.randint(lo, hi) for _ in range(k))]}


def long_first(rng, k, length):
    # A first list of length values, then k - 1 lists of one value each, every
    # list above the ones before it: merging one by one walks the whole
    # result, the long list included, each time.
    step = (HI - LO) // (length + k - 2)
    values = [LO + i * step for i in range(length + k - 1)]
    return {"lists": [values[:length]] + [[v] for v in values[length:]]}


def all_equal(rng, k, length, value):
    return {"lists": [[value] * length for _ in range(k)]}
