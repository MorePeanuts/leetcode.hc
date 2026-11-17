#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> after(numCourses);
        std::vector<int> indegree(numCourses);
        for (const auto& edge : prerequisites) {
            after[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        std::vector<int> queue;
        for (int course = 0; course < numCourses; course++)
            if (indegree[course] == 0) queue.push_back(course);
        for (size_t head = 0; head < queue.size(); head++) {
            for (int next : after[queue[head]])
                if (--indegree[next] == 0) queue.push_back(next);
        }
        return queue.size() == static_cast<size_t>(numCourses);
    }
};
