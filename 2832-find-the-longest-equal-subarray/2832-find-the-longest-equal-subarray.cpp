class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {

        int left = 0;
        int right = 0;
        unordered_map<int, int> mp;
        int maxCountNum = INT_MIN;
        int ans = INT_MIN;

        while(right < nums.size())
        {
            ++mp[nums[right]];
            maxCountNum = max(mp[nums[right]], maxCountNum);
            if(right - left - maxCountNum >= k)
            {
                --mp[nums[left]];
                ++left;
            }
            ans = max(ans, maxCountNum);

            ++right;
        }
        return ans;
        
    }
};