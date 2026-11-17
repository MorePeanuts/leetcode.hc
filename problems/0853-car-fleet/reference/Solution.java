import java.util.Arrays;
import java.util.Comparator;

class Solution {
    private record Car(int position, int speed) {}

    public int carFleet(int target, int[] position, int[] speed) {
        Car[] cars = new Car[position.length];
        for (int i = 0; i < position.length; ++i) {
            cars[i] = new Car(position[i], speed[i]);
        }
        Arrays.sort(cars, Comparator.comparingInt(Car::position).reversed());
        int fleets = 0;
        double slowest = 0;
        for (int i = 0; i < position.length; ++i) {
            double time = (double)(target - cars[i].position()) / cars[i].speed();
            if (time > slowest) {
                ++fleets;
                slowest = time;
            }
        }

        return fleets;
    }
}
