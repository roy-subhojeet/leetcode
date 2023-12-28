class Solution {
private:
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> visited(row, vector<int>(column, 0));

        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < column; ++j)
            {
                if(visited[i][j] == 0 && grid[i][j] == 1)
                {
                    int area = 1;
                    maxArea = max(maxArea, dfs(i, j, visited, grid, area));
                }
            }
        }
        return maxArea;
    }

    int dfs(int row, int column, vector<vector<int>>& visited, vector<vector<int>>& grid, int &area)
    {
        visited[row][column] = 1;
        if(row-1 >=0 && grid[row-1][column] == 1 && !visited[row-1][column]) dfs(row-1, column, visited, grid, ++area);
        if(column+1 < grid[0].size() && grid[row][column+1] == 1 && !visited[row][column+1]) dfs(row, column+1, visited, grid, ++area);
        if(row+1 < grid.size() && grid[row+1][column] == 1 && !visited[row+1][column]) dfs(row+1, column, visited, grid, ++area);
        if(column-1 >= 0 && grid[row][column-1] == 1 && !visited[row][column-1]) dfs(row, column-1, visited, grid, ++area);
        return area;
    }
};