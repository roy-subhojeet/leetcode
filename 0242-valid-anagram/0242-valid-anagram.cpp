class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        for(auto ch: s)
        {
            sMap[ch]++;
        }
        for(auto ch: t)
        {
            tMap[ch]++;
        }
        if(sMap == tMap)
            return true;
        return false;
    }
};