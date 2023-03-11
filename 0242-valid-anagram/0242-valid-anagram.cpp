class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> keyVal;
        map<char, int> resVal;
        if(s.length() != t.length())
            return false;
        for(int i = 0; i < s.size(); i++)
        {
           auto itr = keyVal.find(s[i]);
           if(itr == keyVal.end())
           {
               keyVal.insert(std::pair<char, int>(s[i], 1));
           }
           else
           {
               itr->second++;
           }
        }
        for(int i = 0; i < t.size(); i++)
        {
           auto itr = resVal.find(t[i]);
           if(itr == resVal.end())
           {
               resVal.insert(std::pair<char, int>(t[i], 1));
           }
           else
           {
               itr->second++;
           }
        }
    return (keyVal == resVal);
    }
};