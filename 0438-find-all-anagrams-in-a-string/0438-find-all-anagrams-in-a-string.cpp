class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())
            return {};

        //unordered_map<char, int> mp;
        vector<int> mp(26, 0);

        //unordered_map<char, int> sMp;
        vector<int> sMp(26, 0);
        for(auto &c : p)
        {
            ++mp[c - 'a'];
        }
        
        int right = 0;
        int left = 0;
        int N = p.size();
        int formed = 0;
        vector<int> res;

        while(right < s.size())
        {
            ++sMp[s[right] - 'a'];
            if(right - left + 1 == N)
            {
                if(sMp == mp) res.push_back(left);
                --sMp[s[left] - 'a'];
                ++left;
            }
            ++right;
        }
        return res;
    }
};