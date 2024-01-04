class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto & n : nums)
        {
            ++mp[n];
        }
        int count = 0;
        for(auto &elem : mp)
        {
            if(elem.second == 1) return -1;
            if(elem.second % 3 == 0) count += elem.second/3;
            else count += elem.second/3 + 1;
        }
        return count;
    }
};