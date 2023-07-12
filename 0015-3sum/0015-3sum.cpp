class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                break;
            }
            if(i !=0 && nums[i] == nums[i-1])
            {
                continue;
            }
            int head = i+1;
            int tail = nums.size() - 1;
            while(head < tail)
            {
                if(nums[i] + nums[head] + nums[tail] > 0)
                    --tail;
                else if(nums[i] + nums[head] + nums[tail] < 0)
                    ++head;
                else if(nums[i] + nums[head] + nums[tail] == 0)
                {
                    result.push_back({nums[i], nums[head], nums[tail]});
                    
                    // Avoid duplicates when moving pointers
                    //while(head < tail && nums[head] == nums[head + 1]) ++head;
                    while(head < tail && nums[tail] == nums[tail - 1]) --tail;
                    
                    ++head;
                    --tail;
                }
            }
        }
        return result;
    }
};
