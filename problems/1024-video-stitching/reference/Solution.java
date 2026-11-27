class Solution {
    public int videoStitching(int[][] clips, int time) {
        int[] ends = new int[time];
        for (int[] clip : clips) {
            if (clip[0] < time) ends[clip[0]] = Math.max(ends[clip[0]], clip[1]);
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
}
