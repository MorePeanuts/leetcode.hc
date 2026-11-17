function findOrder(numCourses: number, prerequisites: number[][]): number[] {
    const after: number[][] = Array.from({ length: numCourses }, () => []);
    const indegree = new Int32Array(numCourses);
    for (const [course, prerequisite] of prerequisites) {
        after[prerequisite].push(course);
        indegree[course]++;
    }
    const queue: number[] = [];
    for (let course = 0; course < numCourses; course++)
        if (indegree[course] === 0) queue.push(course);
    for (let head = 0; head < queue.length; head++) {
        for (const next of after[queue[head]])
            if (--indegree[next] === 0) queue.push(next);
    }
    return queue.length === numCourses ? queue : [];
}
