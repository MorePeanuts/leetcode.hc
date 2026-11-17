function timeRequiredToBuy(tickets, k) {
    const n = tickets.length;
    let target = tickets[k];
    let total = 0;
    for (let i = 0; i < n; i++) {
        let limit = i <= k ? target : target - 1;
        total += tickets[i] < limit ? tickets[i] : limit;
    }
    return total;
}
