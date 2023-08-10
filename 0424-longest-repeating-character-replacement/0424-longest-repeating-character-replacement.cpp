class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int maxChar = 0;
        unordered_map<char, int> mp;
        int res  = 0;

        for(auto &str: s)
        {
            ++mp[str];
            maxChar = max(mp[str], maxChar);
            if(j - i + 1 - maxChar > k)
            {
                --mp[s[i]];
                int mpMax = 0;
                /* Optimisation trick: Observe Notes
                for(auto &m: mp)
                {
                    mpMax = max(mpMax, m.second);
                }
                maxChar = mpMax;
                */
                ++i;
            }
            res = max(res, j - i + 1);
            ++j;
        }
        return res;
    }
};