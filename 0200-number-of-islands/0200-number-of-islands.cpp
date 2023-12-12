class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        /* Using BFS */
        queue<pair<int, int>> neighbours;
        int row = grid.size();
        int ans = 0;
        int column = grid[0].size();
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < column; ++j)
            {
                if(grid[i][j] == '1') 
                {
                    neighbours.push({i,j});
                    grid[i][j] = '0';
                    ++ans;
                }
                while(!neighbours.empty())
                {
                    auto val = neighbours.front();
                    neighbours.pop();
                    int r = val.first;
                    int c = val.second;
                    if(r-1 >= 0 && grid[r-1][c] == '1') 
                    {
                        neighbours.push({r-1, c});
                        grid[r-1][c] = '0';
                    }
                    if(r+1 < row && grid[r+1][c] == '1') 
                    {
                        neighbours.push({r+1, c});
                        grid[r+1][c] = '0';
                    }
                    if(c-1 >= 0 && grid[r][c-1] == '1')
                    {
                         neighbours.push({r, c-1});
                         grid[r][c-1] = '0';
                    }
                    if(c+1 < column && grid[r][c+1] == '1') 
                    {
                        neighbours.push({r, c+1});
                        grid[r][c+1] = '0';
                    }
                }
            }
        }
        return ans;
    }
/* DFS 
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
*/
};