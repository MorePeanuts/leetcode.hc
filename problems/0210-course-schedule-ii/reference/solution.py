from collections import deque

class Solution:
    def findOrder(self, numCourses, prerequisites):
        after = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        for course, prerequisite in prerequisites:
            after[prerequisite].append(course)
            indegree[course] += 1
        queue = deque(i for i in range(numCourses) if indegree[i] == 0)
        result = []
        while queue:
            course = queue.popleft()
            result.append(course)
            for nxt in after[course]:
                indegree[nxt] -= 1
                if indegree[nxt] == 0:
                    queue.append(nxt)
        return result if len(result) == numCourses else []
