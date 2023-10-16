class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1, 1};
        vector<vector<int>> res(rowIndex+1, vector<int>());
        res[0] = {1};
        res[1] = {1,1};

        for(int i = 2; i < rowIndex+1; ++i)
        {
            res[i].push_back(1);
            for(int j = 1; j < i; ++j)
            {
                res[i].push_back(res[i-1][j-1] + res[i-1][j]);
            }
            res[i].push_back(1);
        }
        return res[rowIndex];

    }
};