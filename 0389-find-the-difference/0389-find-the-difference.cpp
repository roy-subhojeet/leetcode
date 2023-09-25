class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.empty()) return t[0];
        unordered_map<char, int> mp;
        for(auto & c : s)
        {
            ++mp[c];
        }

        for(auto & ct : t)
        {
            auto itr = mp.find(ct);
            if(itr == mp.end())
            {
                return ct;
            }
            else
            {
                --mp[ct];
                if(mp[ct] == 0) mp.erase(itr->first);
            }
        }
        return t[0];
    }
};