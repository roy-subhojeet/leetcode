class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int max1 = rob_houses(0, n-2, nums);
        int max2 = rob_houses(1, n-1, nums);
        return max(max1, max2);
    }
    int rob_houses(int start, int end, vector<int> &nums)
    {
        vector<int> dp(end+2, 0);
        dp[end] = nums[end];
        for(int i= end-1; i >= start; --i)
        {
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        }
        return dp[start];
    }
};