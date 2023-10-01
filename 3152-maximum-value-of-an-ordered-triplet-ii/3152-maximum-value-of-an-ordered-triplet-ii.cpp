class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int n = nums.size();
        vector<int> maxArray(n, INT_MIN);
        vector<int> maxDiff(n, INT_MAX);
        //vector<int> maxRight(n, INT_MIN); // No need
        maxArray[0] = nums[0];
        for(int i = 1 ; i < n; ++i)
        {
            maxArray[i] = max(nums[i], maxArray[i-1]);
        }
        maxDiff[0] = maxArray[0] - nums[0];
        int maxDif = INT_MIN;
        int pos = 0;
        for(int i = 1 ; i < n; ++i)
        {
            maxDiff[i] = max(maxArray[i] - nums[i], maxDiff[i-1]);
        }
        /* No Need
        maxRight[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; --i)
        {
            maxRight[i] = max(nums[i], maxRight[i+1]);
        }
        long long ans = LLONG_MIN;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            ans = max((long long)maxDiff[i] * maxRight[i+1], ans);
        }
        */

        long long ans = LLONG_MIN;
        for(int i = 2; i < nums.size(); ++i)
        {
            ans = max((long long)maxDiff[i-1] * nums[i], ans);
        }
        
        return ans>0 ? ans: 0;
        
    }
};