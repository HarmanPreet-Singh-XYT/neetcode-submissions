class Solution {
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>> values){
        int ROW = grid.size(),COL = grid[0].size();
        if(min(r,c) < 0 || ROW == r || COL == c || grid[r][c] || values[r][c]){
            return 0;
        }
        if(r == ROW-1 && c == COL-1){
            return 1;
        }
        values[r][c] = 1;
        int count = 0;
        count += dfs(grid, r + 1, c, values);
        count += dfs(grid, r - 1, c, values);
        count += dfs(grid, r, c + 1, values);
        count += dfs(grid, r, c - 1, values);
        values[r][c] = 0;
        return count;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int ROW = grid.size(),COL = grid[0].size();
        vector<vector<int>> visit(ROW,vector<int>(COL,0));
        return dfs(grid,0,0,visit);
    }
};
