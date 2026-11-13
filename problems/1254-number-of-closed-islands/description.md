# 1254. Number of Closed Islands

Given a 2D `grid` consists of `0s` (land) and `1s` (water). An *island* is a maximal 4-directionally connected group of `0s` and a *closed island* is an island **totally** (all left, top, right, bottom) surrounded by `1s.`

Return the number of *closed islands*.

**Example 1:**

![](assets/sample_3_1610.png)

**Input:** grid = \[\[1,1,1,1,1,1,1,0],\[1,0,0,0,0,1,1,0],\[1,0,1,0,1,1,1,0],\[1,0,0,0,0,1,0,1],\[1,1,1,1,1,1,1,0]]

**Output:** 2

**Explanation:**

- The grid contains four islands of 0s.
- The island spanning rows 1 to 3 and columns 1 to 4 is surrounded entirely by 1s. It also encloses the water cell at row 2, column 2. It is therefore closed.
- The single 0 at row 3, column 6 has 1s on all four sides, so it is also closed.
- The two remaining islands both lie in column 7, which is on the border of the grid, so neither of them is closed.
- Two islands are closed, shown in gray, so the answer is 2.

**Example 2:**

![](assets/sample_4_1610.png)

**Input:** grid = \[\[0,0,1,0,0],\[0,1,0,1,0],\[0,1,1,1,0]]

**Output:** 1

**Explanation:**

- The grid contains three islands of 0s.
- The single 0 at row 1, column 2 has 1s above it, below it, to its left and to its right, so it is closed. It is shown in gray.
- The island formed by rows 0 to 2 of column 0 together with row 0, column 1 lies on the border, so it is not closed.
- The island formed by rows 0 to 2 of column 4 together with row 0, column 3 also lies on the border, so it is not closed.
- One island is closed, so the answer is 1.

**Example 3:**

**Input:** grid = \[\[1,1,1,1,1,1,1],\[1,0,0,0,0,0,1],\[1,0,1,1,1,0,1],\[1,0,1,0,1,0,1],\[1,0,1,1,1,0,1],\[1,0,0,0,0,0,1],\[1,1,1,1,1,1,1]]

**Output:** 2

**Explanation:**

- The grid contains two islands of 0s, one nested inside the other.
- The outer island is the ring of 0s occupying rows 1 to 5 and columns 1 to 5. It is enclosed by the outer border of 1s, so it is closed.
- The inner island is the single 0 at row 3, column 3. It is enclosed by the inner ring of 1s, so it is also closed.
- Both islands are closed, so the answer is 2.

**Constraints:**

- `1 <= grid.length, grid[0].length <= 100`
- `0 <= grid[i][j] <=1`
