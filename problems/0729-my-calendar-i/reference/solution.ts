class MyCalendar {
    private readonly events: [number, number][] = [];

    book(startTime: number, endTime: number): boolean {
        let lo = 0;
        let hi = this.events.length;
        while (lo < hi) {
            const mid = lo + Math.floor((hi - lo) / 2);
            if (this.events[mid][0] < startTime) lo = mid + 1;
            else hi = mid;
        }
        if (lo > 0 && this.events[lo - 1][1] > startTime) return false;
        if (lo < this.events.length && this.events[lo][0] < endTime) return false;
        this.events.splice(lo, 0, [startTime, endTime]);
        return true;
    }
}
