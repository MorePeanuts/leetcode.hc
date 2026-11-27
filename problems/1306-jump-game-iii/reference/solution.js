function canReach(arr, start) {
    const seen = new Uint8Array(arr.length);
    seen[start] = 1;
    const stack = [start];
    while (stack.length > 0) {
        const i = stack.pop();
        if (arr[i] === 0) return true;
        for (const j of [i - arr[i], i + arr[i]]) {
            if (j >= 0 && j < arr.length && !seen[j]) {
                seen[j] = 1;
                stack.push(j);
            }
        }
    }
    return false;
}
