def validate_tree(output, wanted, balanced=False):
    """Validate the serialized tree without fixing one acceptable tree shape."""
    if not isinstance(output, list):
        return 'output must be a level-order tree array'
    if not output:
        return None if not wanted else 'output is missing required nodes'
    if type(output[0]) is not int:
        return 'a non-empty tree must have an integer root'
    if any(value is not None and type(value) is not int for value in output):
        return 'tree values must be integers, not booleans or other types'
    values = [output[0]]
    children = [[None, None]]
    cursor = 1
    parent = 0
    while parent < len(values):
        for side in range(2):
            if cursor < len(output):
                value = output[cursor]
                cursor += 1
                if value is not None:
                    children[parent][side] = len(values)
                    values.append(value)
                    children.append([None, None])
        parent += 1
    if any(value is not None for value in output[cursor:]):
        return 'tree contains unreachable nodes'
    if len(values) != len(wanted):
        return 'tree has an incorrect number of nodes'
    ordered = []
    stack = []
    node = 0
    while node is not None or stack:
        while node is not None:
            stack.append(node)
            node = children[node][0]
        node = stack.pop()
        ordered.append(values[node])
        node = children[node][1]
    if ordered != wanted:
        return 'inorder values must equal the required sorted values exactly'
    if balanced:
        heights = [0] * len(values)
        for node in range(len(values)-1, -1, -1):
            left, right = children[node]
            a = 0 if left is None else heights[left]
            b = 0 if right is None else heights[right]
            if abs(a-b) > 1:
                return 'every node must have subtree heights differing by at most one'
            heights[node] = 1 + max(a, b)
    return None


def check(input, output, expected):
    return validate_tree(output, input["nums"], balanced=True)
