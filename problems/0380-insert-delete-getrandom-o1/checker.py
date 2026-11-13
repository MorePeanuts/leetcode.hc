import math


def check(input, output, expected):
    ops, args = input["ops"], input["args"]
    if not isinstance(output, list) or len(output) != len(ops):
        return "expected one result per operation"
    if output[0] is not None:
        return "constructor must return null"
    members = set()
    counts = {}
    samples = 0
    # Each unchanged-set run has <= m buckets and there are <= m runs.
    # Hoeffding per bucket and a union bound over <= m*m tests give
    # false rejection <= 1e-12 per entire case (hence <= 1e-9).
    # Only observed outcomes are stored: never copy or sort the live set.
    log_bound = math.log(2 * len(ops) ** 2 / 1e-12)

    def distribution():
        if not samples:
            return None
        mean = samples / len(members)
        tolerance = math.sqrt(samples * log_bound / 2)
        if len(counts) < len(members) and mean > tolerance:
            return "getRandom never selected some current elements"
        if any(abs(count - mean) > tolerance for count in counts.values()):
            return "getRandom frequencies are inconsistent with a uniform distribution"
        return None

    for i in range(1, len(ops)):
        op, arg, result = ops[i], args[i], output[i]
        if op == "getRandom":
            if type(result) is not int or result not in members:
                return f"operation {i}: getRandom must return a current integer member"
            counts[result] = counts.get(result, 0) + 1
            samples += 1
        else:
            val = arg[0]
            present = val in members
            correct = not present if op == "insert" else present
            if type(result) is not bool or result != correct:
                return f"operation {i}: {op} returned an incorrect boolean"
            # Failed updates do not change the distribution's support.
            if correct:
                error = distribution()
                if error:
                    return error
                counts = {}
                samples = 0
                if op == "insert":
                    members.add(val)
                else:
                    members.remove(val)
    return distribution()
