class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int i = 0; 
        int find_elem = 0;
        vector<int> res;
        for(auto elem: nums)
        {
            find_elem = target - elem;
            if(mp.find(find_elem) != mp.end())
            {
                res.push_back(i);
                res.push_back(mp[find_elem]);
                return res;
            }
            mp[elem] = i;
            i++;
        }
        return res;
    }
};