class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        
        unordered_map<char, int> tMap;
        for (char c : t) {
            ++tMap[c];
        }
        
        unordered_map<char, int> resMap;
        int left = 0, right = 0, required = tMap.size(), formed = 0;
        int minLen = INT_MAX, minLeft = 0;

        while (right < s.size()) {
            char c = s[right];
            ++resMap[c];
            
            if (tMap.find(c) != tMap.end() && resMap[c] == tMap[c]) {
                ++formed;
            }

            while (formed == required) {
                char temp = s[left];

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                --resMap[temp];
                if (tMap.find(temp) != tMap.end() && resMap[temp] < tMap[temp]) {
                    --formed;
                }

                ++left;
            }

            ++right;
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
