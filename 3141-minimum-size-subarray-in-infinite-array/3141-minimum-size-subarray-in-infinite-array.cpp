class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        vector<int> newNums = nums;
        for(auto i: nums)
        {
            newNums.push_back(i);
        }
        long long totalSum = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            totalSum += nums[i];
        }
        int moduloTarget = target%totalSum;
        int repetition = target/totalSum;
        if(!moduloTarget) return nums.size()*repetition;
        int left = 0;
        long long sm = 0;
        int ans = INT_MAX;
        for(int right = 0; right < newNums.size(); ++right)
        {
            sm +=newNums[right];
            while(sm > moduloTarget)
            {
                sm -= newNums[left++];
            }
            if(sm == moduloTarget)
            {
                ans = min(ans, right - left + 1);
            }
        }
        if(ans != INT_MAX) return nums.size()*repetition + ans;
        return -1;


    }
};