function minWindow(s, t) {
    let length = s.length;
    let missing = t.length;
    const need = new Int32Array(128);
    for (let i = 0; i < missing; i++) need[t.charCodeAt(i)]++;
    let left = 0;
    let bestStart = 0;
    let bestLength = length + 1;
    for (let right = 0; right < length; right++) {
        if (need[s.charCodeAt(right)]-- > 0) missing--;
        if (missing === 0) {
            while (need[s.charCodeAt(left)] < 0) {
                need[s.charCodeAt(left)]++;
                left++;
            }
            let windowLength = right - left + 1;
            if (windowLength < bestLength) {
                bestLength = windowLength;
                bestStart = left;
            }
            need[s.charCodeAt(left)]++;
            missing++;
            left++;
        }
    }
    return bestLength <= length ? s.slice(bestStart, bestStart + bestLength) : "";
}
