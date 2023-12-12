class Solution {
public:
    void dfs(vector<vector<char>> &grid, int row, int column)
    {
        grid[row][column] = '0';
        if(row -1 >= 0 && grid[row-1][column] == '1' ) dfs(grid, row-1, column);
        if(row + 1 < grid.size() && grid[row+1][column] == '1') dfs(grid, row+1, column);
        if(column + 1 < grid[0].size() && grid[row][column+1] == '1') dfs(grid, row, column+1);
        if(column -  1 >= 0 && grid[row][column-1] == '1') dfs(grid, row, column-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int ans = 0;
        int column = grid[0].size();
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < column; ++c) 
            {
                if(grid[r][c] == '1') 
                {
                    dfs(grid, r, c);
                    ++ans;
                }
            }
        }
        return ans;
    }
};