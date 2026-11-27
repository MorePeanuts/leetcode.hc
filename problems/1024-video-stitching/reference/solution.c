int videoStitching(int** clips, int clipsSize, int* clipsColSize, int time) {
    int ends[101] = {0};
    for (int i = 0; i < clipsSize; i++) {
        int start = clips[i][0], end = clips[i][1];
        if (end > ends[start]) ends[start] = end;
    }

    int used = 0, covered = 0, farthest = 0;
    for (int start = 0; start < time; start++) {
        if (ends[start] > farthest) farthest = ends[start];
        if (start == covered) {
            if (farthest == covered) return -1;
            covered = farthest;
            used++;
        }
    }
    return used;
}
