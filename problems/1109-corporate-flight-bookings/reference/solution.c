#include <stdlib.h>

int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize) {
    int* result = calloc((size_t)n, sizeof(*result));
    *returnSize = n;
    for (int i = 0; i < bookingsSize; i++) {
        int first = bookings[i][0] - 1;
        int last = bookings[i][1];
        int seats = bookings[i][2];
        result[first] += seats;
        if (last < n) result[last] -= seats;
    }
    for (int i = 1; i < n; i++) result[i] += result[i - 1];
    return result;
}
