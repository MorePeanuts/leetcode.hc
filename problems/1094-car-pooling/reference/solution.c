bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    int* difference = calloc((size_t)(1001), sizeof(*difference));
    for (int i = 0; i < tripsSize; ++i) {
        difference[trips[i][1]] += trips[i][0];
        difference[trips[i][2]] -= trips[i][0];
    }
    int onboard = 0;
    bool feasible = true;
    for (int i = 0; i <= 1000; ++i) {
        onboard += difference[i];
        if (onboard > capacity) {
            feasible = false;
            break;
        }
    }
    free(difference);
    return feasible;
}
