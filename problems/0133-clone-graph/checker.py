def check(input, output, expected):
    adjacency = input["node"] or []
    if not isinstance(output, list) or len(output) != len(adjacency):
        return "The copy must contain exactly the original vertices"
    for index, neighbors in enumerate(output):
        if not isinstance(neighbors, list) or any(type(v) is not int for v in neighbors):
            return "Each adjacency row must be an array of integer node values"
        if sorted(neighbors) != sorted(adjacency[index]):
            return "Node %d has different neighbors from the input" % (index + 1)
    return True
