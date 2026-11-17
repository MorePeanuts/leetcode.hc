int singleNumber(int *nums, int n) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer ^= nums[i];
    }
    return answer;
}
