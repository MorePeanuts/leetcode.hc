#include <stdbool.h>

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int n = roomsSize;
    int color[1000] = {0};
    int stack[1000];
    color[0] = 1;
    stack[0] = 0;
    int count = 1;
    int visited = 1;
    while (count > 0) {
        int node = stack[--count];
        for (int i = 0; i < roomsColSize[node]; i++) {
            int neighbor = rooms[node][i];
            if (color[neighbor] == 0) {
                color[neighbor] = 1;
                stack[count++] = neighbor;
                visited++;
            }
        }
    }
    return visited == n;
}
