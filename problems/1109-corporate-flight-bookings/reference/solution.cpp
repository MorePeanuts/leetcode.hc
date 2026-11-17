class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> result(n);
        for (int i = 0; i < static_cast<int>(bookings.size()); i++) {
            int first = bookings[i][0] - 1;
            int last = bookings[i][1];
            int seats = bookings[i][2];
            result[first] += seats;
            if (last < n) result[last] -= seats;
        }
        for (int i = 1; i < n; i++) result[i] += result[i - 1];
        return result;
    }
};
