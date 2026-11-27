function videoStitching(clips, time) {
    const ends = new Int32Array(time);
    for (const [start, end] of clips) {
        if (start < time) ends[start] = Math.max(ends[start], end);
    }

    let used = 0, covered = 0, farthest = 0;
    for (let start = 0; start < time; start++) {
        if (ends[start] > farthest) farthest = ends[start];
        if (start === covered) {
            if (farthest === covered) return -1;
            covered = farthest;
            used++;
        }
    }
    return used;
}
