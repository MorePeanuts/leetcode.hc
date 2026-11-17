#include <stdbool.h>
#include <stdlib.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int* starts = malloc((size_t)numCourses * sizeof(*starts));
    int* indegree = calloc((size_t)numCourses, sizeof(*indegree));
    int* next = malloc((size_t)prerequisitesSize * sizeof(*next));
    int* queue = malloc((size_t)numCourses * sizeof(*queue));
    for (int i = 0; i < numCourses; i++) starts[i] = -1;
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prerequisite = prerequisites[i][1];
        next[i] = starts[prerequisite];
        starts[prerequisite] = i;
        indegree[course]++;
    }
    int count = 0;
    for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0) queue[count++] = i;
    for (int head = 0; head < count; head++) {
        int course = queue[head];
        for (int edge = starts[course]; edge >= 0; edge = next[edge]) {
            int target = prerequisites[edge][0];
            if (--indegree[target] == 0) queue[count++] = target;
        }
    }
    free(starts);
    free(indegree);
    free(next);
    free(queue);
    return count == numCourses;
}
