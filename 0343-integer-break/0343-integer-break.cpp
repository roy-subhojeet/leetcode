class Solution {
vector<int> memo;
public:
    int integerBreak(int n) {
        memo = vector<int>(n+1, 0);
        if(n <= 3) return n-1;
        return dp(n);
    }
    int dp(int n)
    {
        if(n <= 3) return n;

        if(memo[n] != 0) return memo[n];

        int ans = n;
        for(int i = 1; i < n; ++i)
        {
            ans = max(ans, i * dp(n-i));
        }
        memo[n] = ans;
        return ans;
    }
};