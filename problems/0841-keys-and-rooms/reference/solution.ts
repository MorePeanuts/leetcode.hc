function canVisitAllRooms(rooms: number[][]): boolean {
    let n = rooms.length;
    const color = new Int8Array(n);
    const stack = new Int32Array(n);
    color[0] = 1;
    stack[0] = 0;
    let count = 1;
    let visited = 1;
    while (count > 0) {
        let node = stack[--count];
        for (const neighbor of rooms[node]) {
            if (color[neighbor] === 0) {
                color[neighbor] = 1;
                stack[count++] = neighbor;
                visited++;
            }
        }
    }
    return visited === n;
}
