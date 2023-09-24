class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        if(poured - 1 < query_row) return 0.0;

        vector<vector<double>> ans(query_row+2, vector<double>(query_row+2,0));

        ans[0][0] = poured; 

        for(int i = 0; i <= query_row; ++i)
        {
            for(int j = 0; j < i + 1; ++j)
            {
                double overflow = (ans[i][j] - 1.0)/2.0;
                if(overflow > 0)
                {
                    ans[i+1][j] += overflow;
                    cout << ans[i+1][j] <<endl;
                    ans[i+1][j+1] += overflow; 
                } 
            }
        }

        return min(1.0, ans[query_row][query_glass]);
        
    }
};