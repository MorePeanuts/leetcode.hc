function kClosest(points, k) {
    function distance(point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    points.sort((a, b) => distance(a) - distance(b));
    return points.slice(0, k);
}
