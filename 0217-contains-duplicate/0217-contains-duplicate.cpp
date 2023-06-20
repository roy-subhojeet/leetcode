class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            int key = nums[i];
            mp[key].push_back(key);
        }
        for (auto const& x: mp)
        {
            if (x.second.size() > 1)
                return true;
        }
    return false;
    }
};