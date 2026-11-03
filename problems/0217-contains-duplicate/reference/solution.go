package main

import "sort"

func containsDuplicate(nums []int) bool {
	s := append([]int(nil), nums...)
	sort.Ints(s)
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			return true
		}
	}
	return false
}
