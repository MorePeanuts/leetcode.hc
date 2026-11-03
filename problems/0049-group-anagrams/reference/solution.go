package main

// Keys the groups by letter counts, and returns the groups and the strings
// in each in the reverse of the Python reference's order, to prove that the
// judge ignores both orders.
func groupAnagrams(strs []string) [][]string {
	index := map[[26]int]int{}
	var groups [][]string
	for _, s := range strs {
		var key [26]int
		for i := 0; i < len(s); i++ {
			key[s[i]-'a']++
		}
		g, ok := index[key]
		if !ok {
			g = len(groups)
			index[key] = g
			groups = append(groups, nil)
		}
		groups[g] = append(groups[g], s)
	}
	out := make([][]string, 0, len(groups))
	for i := len(groups) - 1; i >= 0; i-- {
		g := groups[i]
		rev := make([]string, len(g))
		for j, s := range g {
			rev[len(g)-1-j] = s
		}
		out = append(out, rev)
	}
	return out
}
