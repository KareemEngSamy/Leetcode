# BFS Helper for 2D Grid Traversal

## Overview
* The BFS Helper is a reusable function that performs a breadth-first search (BFS) on a 2D grid. It can be used to explore connected regions of the same type, such as connected components of land in a map, regions of color in an image, or reachable cells in a maze.
* The function is designed to be flexible and accepts parameters that define what to consider as traversable cells and how to mark them once visited.


## Function Prototype

```cpp
void bfs(
    vector<vector<char>>& grid,
    int startRow,
    int startCol,
    char landChar,
    char visitedChar,
    const vector<pair<int, int>>& directions
);
```

### Parameter Description:

* `grid`: Reference to a 2D grid (matrix) containing elements of type 'char'.
  Represents the environment or map you are exploring.

* `startRow`: Integer specifying the starting row index where BFS begins.

* `startCol`: Integer specifying the starting column index where BFS begins.

* `landChar`: The target character value to explore.
  For example, '1'could represent land cells, 'A' could represent a color region, etc.

* `visitedChar`: The character used to mark visited cells so they are not revisited.
  For example, marking '1' as '0' after visiting.

* `directions`: A list of pairs representing movement directions.
  Commonly includes the four directions **{{-1,0},{1,0},{0,-1},{0,1}}** for up, down, left, and right.
You can also extend it to eight directions to include diagonals.


## How It Works

1. Start from a given cell `(startRow, startCol)` and push it into a queue.
2. Mark the starting cell as visited by replacing its value with `visitedChar`.
3. Repeatedly pop cells from the queue and explore their neighbors in all valid directions.
4. For each neighbor that matches the `landChar`, mark it as visited and enqueue it.
5. Continue until the queue is empty, meaning all connected cells have been explored.


## Code Implementation

```cpp
 static void bfs(
        vector<vector<char>>& grid,
        int startRow,
        int startCol,
        char landChar,
        char visitedChar,
        const vector<pair<int, int>>& directions
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
```


## Example Usage: Counting Islands problem [200]

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    islands++;
                    bfs(grid, i, j, '1', '0', directions);
                }
            }
        }

        return islands;
    }
};
```


## Customization

* You can change `landChar` and `visitedChar` to work with different grid symbols.
To support diagonal traversal, include eight directions instead of four:

```cpp
vector<pair<int,int>> directions = {
    {-1,0}, {1,0}, {0,-1}, {0,1},
    {-1,-1}, {-1,1}, {1,-1}, {1,1}
};
```


## Complexity

* Time Complexity: **O(m × n)** , since each cell is processed at most once.
* Space Complexity: **O(min(m × n, queue size))** , due to the BFS queue.

## Notes

* This BFS implementation is iterative and safe for large grids.
* It avoids recursion stack limits and can be reused for flood fill, connected component counting, maze solving, and similar problems.
