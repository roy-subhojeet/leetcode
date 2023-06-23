class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string, vector<string>> mp;
        for(auto &s: strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        for(auto &m:mp)
        {
            ret.push_back(m.second);
        }
        return ret;
    }
};