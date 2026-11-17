function kClosest(points: number[][], k: number): number[][] {
    function distance(point: number[]) {
        return point[0] * point[0] + point[1] * point[1];
    }
    points.sort((a, b) => distance(a) - distance(b));
    return points.slice(0, k);
}
