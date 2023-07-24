class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0;
        int right = 0;
        unordered_map<char , int> mp;
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
        return res;
    }
};