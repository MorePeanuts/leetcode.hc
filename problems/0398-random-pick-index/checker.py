from collections import Counter, defaultdict
from math import log, sqrt


def check(input, output, expected):
    ops, args = input["ops"], input["args"]
    nums = args[0][0]
    if not isinstance(output, list) or len(output) != len(ops):
        return "expected one result per operation"
    if output[0] is not None:
        return "constructor result must be null"
    positions = defaultdict(list)
    for index, value in enumerate(nums):
        positions[value].append(index)
    counts = defaultdict(Counter)
    for call in range(1, len(ops)):
        target, value = args[call][0], output[call]
        if type(value) is not int or not 0 <= value < len(nums) or nums[value] != target:
            return f"pick result {call} must be an index containing target {target}"
        counts[target][value] += 1
    # All queried targets' individual indices and rank-based groups are
    # fixed buckets. Sum their counts for one union bound over the case.
    k = sum(len(positions[t]) + min(16, len(positions[t])) for t in counts)
    for target, observed in counts.items():
        indices = positions[target]
        size = len(indices)
        n = sum(observed.values())
        groups = min(16, size)
        grouped = [0] * groups
        masses = [0] * groups
        # Hoeffding per bucket, union over all k tested buckets, gives
        # false rejection probability <= 1e-9 for the entire case.
        bound = sqrt(n * log(2 * k / 1e-9) / 2)
        for rank, index in enumerate(indices):
            count = observed[index]
            if abs(count - n / size) > bound:
                return f"target {target}, index {index} has implausible frequency {count}"
            group = rank * groups // size
            grouped[group] += count
            masses[group] += 1
        for group, count in enumerate(grouped):
            if abs(count - n * masses[group] / size) > bound:
                return f"target {target}, index bucket {group} has implausible frequency {count}"
    return None
