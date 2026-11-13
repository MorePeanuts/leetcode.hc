package main

import "strings"

func simplifyPath(path string) string {
	parts := []string{}
	for _, p := range strings.Split(path, "/") {
		if p == ".." {
			if len(parts) > 0 {
				parts = parts[:len(parts)-1]
			}
		} else if p != "" && p != "." {
			parts = append(parts, p)
		}
	}
	return "/" + strings.Join(parts, "/")
}
