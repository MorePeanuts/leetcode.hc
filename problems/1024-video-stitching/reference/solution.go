package main

func videoStitching(clips [][]int, time int) int {
	ends := make([]int, time)
	for _, clip := range clips {
		if start := clip[0]; start < time {
			ends[start] = max(ends[start], clip[1])
		}
	}

	used, covered, farthest := 0, 0, 0
	for start, end := range ends {
		farthest = max(farthest, end)
		if start == covered {
			if farthest == covered {
				return -1
			}
			covered = farthest
			used++
		}
	}
	return used
}
