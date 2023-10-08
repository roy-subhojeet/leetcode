class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int mx = INT_MIN;
        int n = nums.size();


        vector<int> dp(n+1, 0);
        dp[n-1] = nums[n-1];

        for(int i = n-2; i >=  0; --i)
        {
            dp[i] =  max(dp[i+1], nums[i] + dp[i+2]);
        }
        return dp[0];
    }
};