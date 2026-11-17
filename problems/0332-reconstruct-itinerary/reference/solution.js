function findItinerary(tickets) {
    const edges = new Map();
    for (const [from, to] of tickets) {
        const destinations = edges.get(from);
        if (destinations === undefined) edges.set(from, [to]);
        else destinations.push(to);
    }
    for (const destinations of edges.values()) destinations.sort().reverse();
    const stack = ["JFK"];
    const result = [];
    while (stack.length !== 0) {
        const destinations = edges.get(stack[stack.length - 1]);
        if (destinations === undefined || destinations.length === 0) {
            result.push(stack.pop());
        } else {
            stack.push(destinations.pop());
        }
    }
    return result.reverse();
}
