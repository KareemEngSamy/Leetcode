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
                    bfs(grid, i, j, '1', '0', dirs); //grid,startRow,startCol,landChar,visitedChar,directions
                }
            }
        }

        return islands;
    }
};
