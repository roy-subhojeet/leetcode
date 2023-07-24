class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0;
        int right = 0;
        unordered_map<char , int> mp;

        /* Optimised Sliding Window */

        for(auto &st: s)
        {
            if(mp[s[right]] > 0)
            {
                left = max(mp[s[right]], left);
            }
            mp[s[right]] = right + 1;
            ++right;
            res = max (res, right - left);
        }

        /* Unoptimised sliding window
        for(auto &st: s)
        {
            while(mp[st] > 0) 
            {
                char l = s[left];
                --mp[l];
                ++left;
            }
            ++mp[st];
            ++right;
            res = max(res, right - left);
        }
        */
        return res;
    }
};