# 200. Number of Islands

## Problem Statement

Given an `m x n` 2D binary grid representing a map of `'1'`s (**land**) and `'0'`s (**water**),
return the **number of islands**.

An island is surrounded by water and is formed by connecting adjacent lands **horizontally or vertically**.
You may assume that all four edges of the grid are surrounded by water.

---

### Example 1

**Input:**

```cpp
grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
```

**Output:** `1`

---

### Example 2

**Input:**

```cpp
grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
```

**Output:** `3`

---

## 💡 Approach: Breadth-First Search (BFS)

### Key Idea

* Each `'1'` (land) that has not been visited represents the start of a **new island**.
* We use **BFS** to traverse all connected `'1'`s (up, down, left, right).
* As we visit each land cell, we mark it as `'0'` to avoid revisiting.
* Every BFS traversal counts as **one complete island**.

## Algorithm Steps

1. Loop over all cells in the grid.
2. When a `'1'` is found:

   * Increment the island counter.
   * Launch BFS starting from that cell.
3. In BFS:

   * Use a queue to explore all 4-connected neighbors.
   * For each neighbor that is `'1'`, mark it `'0'` and enqueue it.
4. Continue until all connected land cells are marked visited.
5. Return the number of BFS launches (islands found).


## Example Walkthrough

For:

```
1 1 0 0 0  
1 1 0 0 0  
0 0 1 0 0  
0 0 0 1 1
```

* First BFS starts at `(0,0)` → marks the first 4 cells → **island #1**
* Second BFS starts at `(2,2)` → marks 1 cell → **island #2**
* Third BFS starts at `(3,3)` → marks `(3,3)` and `(3,4)` → **island #3**

Total islands = **3**

## Complexity

Time Complexity:
**O(m × n)** -> Each cell is visited once during the traversal.

Space Complexity:
**O(min(m × n, queue size))** -> Due to the BFS queue that can hold at most all cells of one island.



## Code (C++)

```cpp
class Solution {
public:

    // Generic BFS for any 2D grid traversal
    void bfs(
            vector<vector<char>>& grid, 
            int startRow, 
            int startCol,
            char landChar, 
            char visitedChar, 
            const vector<pair<int,int>>& directions
            ) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({startRow, startCol});
        grid[startRow][startCol] = visitedChar;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == landChar) {
                    grid[nr][nc] = visitedChar;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++islands;
                    bfs(grid, i, j, '1', '0', dirs); // grid,startRow,startCol,landChar,visitedChar,directions
                }
            }
        }

        return islands;
    }
};
```


## Notes

* The BFS helper is **generic** and reusable for other grid-based problems like flood fill or connected components.
* You can modify the `directions` vector for **8-directional** movement if diagonals should connect lands.
* For recursion lovers, this can also be implemented with **DFS** (recursive or stack-based).
