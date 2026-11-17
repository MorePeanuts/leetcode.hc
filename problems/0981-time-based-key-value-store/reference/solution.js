class TimeMap {
    constructor() {
        this.histories = new Map();
    }

    set(key, value, timestamp) {
        let history = this.histories.get(key);
        if (history === undefined) {
            history = [];
            this.histories.set(key, history);
        }
        history.push({ timestamp, value });
    }

    get(key, timestamp) {
        const history = this.histories.get(key);
        if (history === undefined) {
            return "";
        }
        let left = 0;
        let right = history.length;
        while (left < right) {
            const mid = left + ((right - left) >> 1);
            if (history[mid].timestamp <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left === 0 ? "" : history[left - 1].value;
    }
}
