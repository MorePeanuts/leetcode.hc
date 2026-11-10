package main

import "sort"

func carFleet(target int, position []int, speed []int) int {
	n := len(position)
	idx := make([]int, n)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(a, b int) bool { return position[idx[a]] > position[idx[b]] })
	// The time of the fleet ahead is leadDist / leadSpeed; a car arrives
	// later when dist / speed is greater, compared without division.
	fleets := 0
	leadDist, leadSpeed := 0, 1
	for _, i := range idx {
		dist := target - position[i]
		if dist*leadSpeed > leadDist*speed[i] {
			fleets++
			leadDist, leadSpeed = dist, speed[i]
		}
	}
	return fleets
}
