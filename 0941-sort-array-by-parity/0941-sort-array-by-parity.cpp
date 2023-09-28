class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        vector<int> oddList;
        for(auto & i : nums)
        {
            if(i%2 == 0) ans.push_back(i);
            else oddList.push_back(i);
        }
        for(auto &j : oddList)
        {
            ans.push_back(j);
        }
        return ans;
    }
};