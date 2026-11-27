package main

import "sort"

func accountsMerge(accounts [][]string) [][]string {
	parent := make([]int, len(accounts))
	for i := range parent {
		parent[i] = i
	}
	root := func(i int) int {
		for parent[i] != i {
			parent[i] = parent[parent[i]]
			i = parent[i]
		}
		return i
	}
	owner := make(map[string]int)
	for i, account := range accounts {
		for _, email := range account[1:] {
			if first, ok := owner[email]; ok {
				parent[root(i)] = root(first)
			} else {
				owner[email] = i
			}
		}
	}
	groups := make([][]string, len(accounts))
	for email, i := range owner {
		r := root(i)
		groups[r] = append(groups[r], email)
	}
	result := [][]string{}
	for i := len(groups) - 1; i >= 0; i-- {
		if len(groups[i]) > 0 {
			sort.Strings(groups[i])
			result = append(result, append([]string{accounts[i][0]}, groups[i]...))
		}
	}
	return result
}
