package main

func canVisitAllRooms(rooms [][]int) bool {
	seen := make([]bool, len(rooms))
	seen[0] = true
	queue := []int{0}
	for head := 0; head < len(queue); head++ {
		for _, key := range rooms[queue[head]] {
			if !seen[key] {
				seen[key] = true
				queue = append(queue, key)
			}
		}
	}
	return len(queue) == len(rooms)
}
