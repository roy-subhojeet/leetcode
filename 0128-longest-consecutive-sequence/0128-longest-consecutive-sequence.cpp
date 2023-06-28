class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> setNums(nums.begin(), nums.end());
        int res = 0;
        for(auto num : nums)
        {
            if(setNums.find(num - 1) == setNums.end())
            {
                int currentNum = num;
                int count = 0;
                while(setNums.find(currentNum) != setNums.end())
                {
                    ++count;
                    ++currentNum;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
