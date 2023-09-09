class Solution {
public:
    long long getMax(long long ll1, long long ll2)
    {
        ll1 = (ll1 > ll2) ?  ll1 :  ll2;
        return ll1;
    }
    long long getMin(long long ll1, long long ll2)
    {
        ll1 = (ll1 < ll2) ? ll1 : ll2;
        return ll1;
    }
    long long gridGame(vector<vector<int>>& grid) {
        long long size = grid[0].size() - 1;
        if (size == 0) return 0;
        long long ans = LONG_MAX;
        long long max = 0;
        vector <long long> prefixSum(size +1, 0);
        vector <long long> suffixSum(size +1, 0);
        //grid[0][0] = 0;
       // grid[1][size] = 0;
        suffixSum[size] = grid[0][size];
        for(long long i = size - 1; i >= 0; --i)
        {
            suffixSum[i] = grid[0][i] + suffixSum[i+1];
        }
        prefixSum[0] = grid[1][0];
        for(long long j = 1; j <= size; ++j)
        {
            prefixSum[j] = prefixSum[j-1] + grid[1][j];
        }
        ans = getMin(ans, suffixSum[1]);
        
        for(long long i = 1; i < size; ++i)
        {
            max = getMax(prefixSum[i-1], suffixSum[i+1]);
            ans = getMin(ans, max);
        }
        ans = getMin(ans, prefixSum[size-1]);

        return ans;
    }
};