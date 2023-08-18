class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())
            return {};

        unordered_map<char, int> mp;
        unordered_map<char, int> sMp;
        for(auto &c : p)
        {
            ++mp[c];
        }
        
        int right = 0;
        int left = 0;
        int N = p.size();
        int formed = 0;
        vector<int> res;

        while(right < s.size())
        {
            ++sMp[s[right]];
            if(right - left + 1 == N)
            {
                if(sMp == mp) res.push_back(left);
                --sMp[s[left]];
                if(sMp[s[left]] == 0) sMp.erase(s[left]);
                ++left;
            }
            ++right;
        }
        return res;
    }
};