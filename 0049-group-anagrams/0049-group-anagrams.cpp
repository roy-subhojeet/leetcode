class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto &s: strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(move(s));
        }
        vector<vector<string>> ret;
        ret.reserve(mp.size());
        for(auto &m:mp)
        {
            ret.push_back(move(m.second));
        }
        return ret;
    }
};