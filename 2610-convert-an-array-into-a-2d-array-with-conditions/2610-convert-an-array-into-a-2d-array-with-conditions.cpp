class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<unordered_set<int>> st;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(st.empty())
            {
                st.push_back({nums[i]});
            }
            else
            {
                bool canInsert = false;
                for(int j = 0; j < st.size(); ++j)
                {
                    if(st[j].find(nums[i]) == st[j].end())
                    {
                        canInsert = true;
                        st[j].insert(nums[i]);
                        break;
                    }
                }
                if(!canInsert) st.push_back({nums[i]});
            }
        }
        vector<vector<int>> ans(st.size(), vector<int>());
        for(int i = 0; i < st.size(); ++i)
        {
            for(auto &num : st[i])
            {
                ans[i].push_back(num);
            }
        }
        return ans;
    }
};