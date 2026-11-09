package main

// A window of len(s1) slides over s2, keeping diff = window counts minus
// s1's counts, and how many of the 26 letters have diff 0.
func checkInclusion(s1 string, s2 string) bool {
	m, n := len(s1), len(s2)
	if m > n {
		return false
	}
	var diff [26]int
	for i := 0; i < m; i++ {
		diff[s1[i]-'a']--
		diff[s2[i]-'a']++
	}
	zero := 0
	for _, d := range diff {
		if d == 0 {
			zero++
		}
	}
	if zero == 26 {
		return true
	}
	for i := m; i < n; i++ {
		in, out := s2[i]-'a', s2[i-m]-'a'
		if in == out {
			continue
		}
		if diff[in] == 0 {
			zero--
		}
		diff[in]++
		if diff[in] == 0 {
			zero++
		}
		if diff[out] == 0 {
			zero--
		}
		diff[out]--
		if diff[out] == 0 {
			zero++
		}
		if zero == 26 {
			return true
		}
	}
	return false
}
