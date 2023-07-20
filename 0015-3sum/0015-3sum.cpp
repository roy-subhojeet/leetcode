class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // No Sort Approach
        vector<vector<int>> fRes;
        set<vector<int>> uRes;
        unordered_map<int, int> mp;
        unordered_set<int> seen;

        for(int i = 0; i < nums.size(); i++)
        {
            if(seen.insert(nums[i]).second)
            {
                for(int j = i+1; j < nums.size(); j++)
                {
                        int complement = -nums[i] - nums[j];
                        auto it = mp.find(complement);
                        if(it != mp.end() && it->second == i)
                        {
                            vector<int> triplet = {nums[i], nums[j], complement};
                            sort(triplet.begin(), triplet.end());
                            uRes.insert(triplet);
                        }
                    mp[nums[j]] = i;
                }
            }
        }
        return vector<vector<int>> (uRes.begin(), uRes.end());

        /* Hash Map Approach
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++)
        {
            unordered_set<int> found;
            if(i !=0 && nums[i] == nums[i-1])
            {
                continue;
            }
            for(int j = i+1; j < nums.size(); j++)
            {
                int complement = -nums[i] - nums[j];
                if(found.count(complement))
                {
                    res.push_back({nums[i], nums[j], complement});
                    while(j+1 < nums.size() && nums[j] == nums[j+1]) ++j;
                }
                found.insert(nums[j]);
            }
        }
        return res;
        /*

        /* Two Pointer Approach
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
        return result; */
    }
};
