function minInterval(intervals, queries) {
    intervals.sort((a, b) => a[0] - b[0]);
    const order = queries.map((_, i) => i).sort((a, b) => queries[a] - queries[b]);
    const answer = new Array(queries.length);
    const heap = [];

    function push(entry) {
        let i = heap.length;
        heap.push(entry);
        while (i > 0) {
            const parent = Math.floor((i - 1) / 2);
            if (heap[parent].length <= entry.length) break;
            heap[i] = heap[parent];
            i = parent;
        }
        heap[i] = entry;
    }

    function pop() {
        const entry = heap.pop();
        if (heap.length === 0) return;
        let i = 0;
        for (let child = 1; child < heap.length; child = 2 * i + 1) {
            if (child + 1 < heap.length && heap[child + 1].length < heap[child].length) child++;
            if (entry.length <= heap[child].length) break;
            heap[i] = heap[child];
            i = child;
        }
        heap[i] = entry;
    }

    let next = 0;
    for (const index of order) {
        const query = queries[index];
        while (next < intervals.length && intervals[next][0] <= query) {
            const [start, end] = intervals[next++];
            push({ length: end - start + 1, end });
        }
        while (heap.length > 0 && heap[0].end < query) pop();
        answer[index] = heap.length > 0 ? heap[0].length : -1;
    }
    return answer;
}
