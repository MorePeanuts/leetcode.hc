package main

func longestSubstring(s string, k int) int {
	if k == 1 {
		return len(s)
	}
	var total [26]int
	for i := range s {
		total[s[i]-'a']++
	}
	possible := 0
	for _, count := range total {
		if count >= k {
			possible++
		}
	}

	best := 0
	for target := 1; target <= possible; target++ {
		var counts [26]int
		left, distinct, qualified := 0, 0, 0
		for right := range s {
			ch := s[right] - 'a'
			if counts[ch] == 0 {
				distinct++
			}
			counts[ch]++
			if counts[ch] == k {
				qualified++
			}
			for distinct > target {
				old := s[left] - 'a'
				if counts[old] == k {
					qualified--
				}
				counts[old]--
				if counts[old] == 0 {
					distinct--
				}
				left++
			}
			if qualified == target {
				best = max(best, right-left+1)
			}
		}
	}
	return best
}
