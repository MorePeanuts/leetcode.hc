def check(input, output, expected):
    if not isinstance(output, list):
        return "The ordering must be an array of course ids"
    if not expected:
        return True if output == [] else "A cyclic graph must return an empty ordering"
    n = input["numCourses"]
    if len(output) != n:
        return "The ordering must contain all %d courses" % n
    if any(type(course) is not int or not 0 <= course < n for course in output):
        return "Every course id must be an integer in [0, numCourses)"
    if len(set(output)) != n:
        return "Each course must occur exactly once"
    position = [0] * n
    for index, course in enumerate(output):
        position[course] = index
    for course, prerequisite in input["prerequisites"]:
        if position[prerequisite] >= position[course]:
            return "Prerequisite %d must precede course %d" % (prerequisite, course)
    return True
