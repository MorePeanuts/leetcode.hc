int timeRequiredToBuy(int *tickets, int n, int k) {
    int target = tickets[k];
    int total = 0;
    for (int i = 0; i < n; i++) {
        int limit = i <= k ? target : target - 1;
        total += tickets[i] < limit ? tickets[i] : limit;
    }
    return total;
}
