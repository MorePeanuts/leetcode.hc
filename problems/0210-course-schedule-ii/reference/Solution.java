import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> after = new ArrayList<>(numCourses);
        for (int i = 0; i < numCourses; i++) after.add(new ArrayList<>());
        int[] indegree = new int[numCourses];
        for (int[] edge : prerequisites) {
            after.get(edge[1]).add(edge[0]);
            indegree[edge[0]]++;
        }
        int[] queue = new int[numCourses];
        int count = 0;
        for (int course = 0; course < numCourses; course++)
            if (indegree[course] == 0) queue[count++] = course;
        for (int head = 0; head < count; head++) {
            for (int next : after.get(queue[head]))
                if (--indegree[next] == 0) queue[count++] = next;
        }
        return count == numCourses ? queue : new int[0];
    }
}
