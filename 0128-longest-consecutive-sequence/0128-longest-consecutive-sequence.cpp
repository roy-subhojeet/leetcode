class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> setNums(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(setNums.find(nums[i] -1) != setNums.end())
                continue;
            else
            {
                int currentNum = nums[i];
                int count = 0;
                while(setNums.find(currentNum) != setNums.end())
                {
                    count ++;
                    currentNum ++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};