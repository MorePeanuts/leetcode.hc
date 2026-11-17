function isNStraightHand(hand, groupSize) {
    if (hand.length % groupSize !== 0) {
        return false;
    }
    const counts = new Map();
    for (const value of hand) {
        counts.set(value, (counts.get(value) ?? 0) + 1);
    }
    hand.sort((a, b) => a - b);
    for (const first of hand) {
        const amount = counts.get(first);
        if (amount === 0) {
            continue;
        }
        for (let value = first; value < first + groupSize; value++) {
            const available = counts.get(value) ?? 0;
            if (available < amount) {
                return false;
            }
            counts.set(value, available - amount);
        }
    }
    return true;
}
