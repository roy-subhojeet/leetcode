class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int i = 0; 
        int find_elem = 0;
        for(auto elem: nums)
        {
            find_elem = target - elem;
            if(mp.find(find_elem) != mp.end())
            {
                return {i, mp[find_elem]};
            }
            mp[elem] = i;
            i++;
        }
        return {0,0};
    }
};