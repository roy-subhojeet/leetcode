class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        unordered_map<int, vector<int>> mp;
        vector<vector<int>> res;
        int idx = 0;

        for(auto &group : groupSizes)
        {
            mp[group].push_back(idx);
            ++idx;
        }

        for(int i = 0; i < groupSizes.size(); ++i)
        {
            auto itr = mp.find(groupSizes[i]);
            int count = 0;
            if(itr != mp.end())
            {
                vector<int> ans;
                for(auto & idx : itr->second)
                {
                    ++count;
                    ans.push_back(idx);
                    if(count%itr->first == 0) 
                    {
                        res.push_back(ans);
                        ans.clear();
                    }
                }
            }
            mp.erase(groupSizes[i]);
        }
        return res;
    }
};