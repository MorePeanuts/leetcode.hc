typedef struct {
    int position;
    int speed;
} Car;

static int byPosition(const void* lhs, const void* rhs) {
    const Car* a = lhs;
    const Car* b = rhs;
    return b->position - a->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    Car* cars = malloc((size_t)positionSize * sizeof(*cars));
    for (int i = 0; i < positionSize; ++i) {
        cars[i] = (Car){position[i], speed[i]};
    }
    qsort(cars, (size_t)positionSize, sizeof(*cars), byPosition);
    int fleets = 0;
    double slowest = 0;
    for (int i = 0; i < positionSize; ++i) {
        double time = (double)(target - cars[i].position) / cars[i].speed;
        if (time > slowest) {
            ++fleets;
            slowest = time;
        }
    }
    free(cars);
    return fleets;
}
