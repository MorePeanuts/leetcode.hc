package main

import "sort"

func findItinerary(tickets [][]string) []string {
	edges := map[string][]string{}
	for _, ticket := range tickets {
		edges[ticket[0]] = append(edges[ticket[0]], ticket[1])
	}
	for _, destinations := range edges {
		sort.Sort(sort.Reverse(sort.StringSlice(destinations)))
	}
	stack := []string{"JFK"}
	route := []string{}
	for len(stack) > 0 {
		source := stack[len(stack)-1]
		destinations := edges[source]
		if len(destinations) > 0 {
			stack = append(stack, destinations[len(destinations)-1])
			edges[source] = destinations[:len(destinations)-1]
		} else {
			route = append(route, source)
			stack = stack[:len(stack)-1]
		}
	}
	for l, r := 0, len(route)-1; l < r; l, r = l+1, r-1 {
		route[l], route[r] = route[r], route[l]
	}
	return route
}
