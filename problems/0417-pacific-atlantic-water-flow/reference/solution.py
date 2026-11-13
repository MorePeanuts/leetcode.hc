class Solution:
    def pacificAtlantic(self, heights):
        rows, cols = len(heights), len(heights[0])
        def reachable(starts):
            seen = set(starts)
            stack = list(seen)
            while stack:
                r,c = stack.pop()
                for nr,nc in ((r-1,c),(r+1,c),(r,c-1),(r,c+1)):
                    if 0 <= nr < rows and 0 <= nc < cols and (nr,nc) not in seen and heights[nr][nc] >= heights[r][c]:
                        seen.add((nr,nc))
                        stack.append((nr,nc))
            return seen
        pacific = reachable([(r,0) for r in range(rows)] + [(0,c) for c in range(cols)])
        atlantic = reachable([(r,cols-1) for r in range(rows)] + [(rows-1,c) for c in range(cols)])
        return [[r,c] for r in range(rows) for c in range(cols) if (r,c) in pacific and (r,c) in atlantic]
