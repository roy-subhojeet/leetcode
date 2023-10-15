class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int runningCount = 0;
        for(auto i : nums)
        {
            if(i == 1) 
            {
                ++runningCount;
            }
            else runningCount = 0;
            maxCount = max(runningCount, maxCount);
        }
        return maxCount;
    }
};