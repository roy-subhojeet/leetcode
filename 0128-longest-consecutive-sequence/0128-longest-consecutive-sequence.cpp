class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> setNums(nums.begin(), nums.end());
        int res;
        for(int i = 0; i < nums.size(); i++)
        {
            int currentNum = nums[i];
            int count = 0;
            if(setNums.find(currentNum -1) != setNums.end())
                continue;
            while(setNums.find(currentNum) != setNums.end())
            {
                count ++;
                currentNum ++;
                res = max(res, count);
            }
        }
        return res;
    }
};