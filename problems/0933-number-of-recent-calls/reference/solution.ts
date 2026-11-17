class RecentCounter {
    private readonly times: number[] = [];
    private head = 0;

    ping(t: number): number {
        this.times.push(t);
        while (this.times[this.head] < t - 3000) {
            this.head++;
        }
        return this.times.length - this.head;
    }
}
