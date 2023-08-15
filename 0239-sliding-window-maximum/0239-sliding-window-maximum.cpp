class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> oMap;
        vector<int> res;
        int left = 0;
        int right = 0;
        int runningCount = 0;
        while(right < nums.size() )
        {
            ++oMap[nums[right]];
            ++runningCount;
            if(runningCount == k)
            {
                res.push_back(oMap.rbegin()->first);
                --oMap[nums[left]];
                if(oMap[nums[left]] == 0) oMap.erase(nums[left]);
                --runningCount;
                ++left;
            }
            ++right;
        }
        return res;
    }
};