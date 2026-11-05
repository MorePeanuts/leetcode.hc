package main

import "sort"

// Fixes the largest element and closes two pointers on the values below it,
// the mirror of the Python reference, which fixes the smallest. It writes
// each triplet in descending order, to prove that the judge ignores the order
// of the triplets and of their elements.
func threeSum(nums []int) [][]int {
	s := append([]int(nil), nums...)
	sort.Ints(s)
	var result [][]int
	for k := len(s) - 1; k >= 2; k-- {
		if s[k] < 0 {
			break
		}
		if k < len(s)-1 && s[k] == s[k+1] {
			continue
		}
		lo, hi := 0, k-1
		for lo < hi {
			switch sum := s[lo] + s[hi] + s[k]; {
			case sum < 0:
				lo++
			case sum > 0:
				hi--
			default:
				result = append(result, []int{s[k], s[hi], s[lo]})
				hi--
				for lo < hi && s[hi] == s[hi+1] {
					hi--
				}
				lo++
			}
		}
	}
	return result
}
