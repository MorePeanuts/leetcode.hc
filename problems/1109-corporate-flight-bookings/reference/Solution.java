class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] result = new int[n];
        for (int i = 0; i < bookings.length; i++) {
            int first = bookings[i][0] - 1;
            int last = bookings[i][1];
            int seats = bookings[i][2];
            result[first] += seats;
            if (last < n) result[last] -= seats;
        }
        for (int i = 1; i < n; i++) result[i] += result[i - 1];
        return result;
    }
}
