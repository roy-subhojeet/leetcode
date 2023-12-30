class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int column = heights[0].size();
        vector<vector<bool>> pacificReachable(row, vector<bool>(column, false));
        vector<vector<bool>> atlanticReachable(row, vector<bool>(column, false));

        for(int i = 0; i < row; ++i)
        {
            dfs(i, 0, pacificReachable, heights);
            dfs(i, column-1, atlanticReachable, heights);
        }

        for(int j = 0; j < column; ++j)
        {
            dfs(0, j, pacificReachable, heights);
            dfs(row-1, j, atlanticReachable, heights);
        }
        vector<vector<int>> res;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < column; ++j)
            {
                if(pacificReachable[i][j]&&atlanticReachable[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
    void dfs(int row, int column, vector<vector<bool>> &oceanReachable, vector<vector<int>>& heights)
    {
        oceanReachable[row][column] = true;
        if(row-1 >= 0 && heights[row-1][column] >= heights[row][column] && !oceanReachable[row-1][column])
        {
            dfs(row-1, column, oceanReachable, heights);
        }
        if(row+1 < oceanReachable.size() &&heights[row+1][column] >= heights[row][column] && !oceanReachable[row+1][column])
        {
            dfs(row+1, column, oceanReachable, heights);
        }
        if(column - 1 >= 0 && heights[row][column-1] >= heights[row][column] && !oceanReachable[row][column-1])
        {
            dfs(row, column-1, oceanReachable, heights);
        }
        if(column + 1 < oceanReachable[0].size() && heights[row][column+1] >= heights[row][column]  && !oceanReachable[row][column+1])
        {
            dfs(row, column+1, oceanReachable, heights);
        }
    }
};