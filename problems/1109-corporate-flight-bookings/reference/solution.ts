function corpFlightBookings(bookings: number[][], n: number): number[] {
    const result = new Array(n).fill(0);
    for (let i = 0; i < bookings.length; i++) {
        let first = bookings[i][0] - 1;
        let last = bookings[i][1];
        let seats = bookings[i][2];
        result[first] += seats;
        if (last < n) result[last] -= seats;
    }
    for (let i = 1; i < n; i++) result[i] += result[i - 1];
    return result;
}
