class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> mpS1(26, 0), window(26, 0);

        // Count the frequency of characters in s1
        for (auto &s : s1) {
            mpS1[s - 'a']++;
        }

        // Create a window of s1.size() in s2
        int left = 0, right = 0;
        while (right < s2.size()) {
            char c = s2[right];
            right++;
            window[c - 'a']++;

            // When the window size is equal to s1's size, check the counts
            if (right - left == s1.size()) {
                if (mpS1 == window) {
                    return true;
                }

                // Slide the window to the right
                char leftChar = s2[left];
                left++;
                window[leftChar - 'a']--;
            }
        }

        return false;
    }

        /* Sliding Window
        if (s1.size() > s2.size()) {
            return false;
        }

        unordered_map<char, int> mpS1, window;

        // Count the frequency of characters in s1
        for (auto &s : s1) {
            mpS1[s]++;
        }

        // Create a window of s1.size() in s2
        int left = 0, right = 0;
        while (right < s2.size()) {
            char c = s2[right];
            right++;
            window[c]++;

            // When the window size is equal to s1's size, check the counts
            if (right - left == s1.size()) {
                if (mpS1 == window) {
                    return true;
                }

                // Slide the window to the right
                char leftChar = s2[left];
                left++;
                window[leftChar]--;
                if (window[leftChar] == 0) {
                    window.erase(leftChar);
                }
            }
        }

        return false;
    }
*/

/* Initial Solution
        if(s1.size() > s2.size())
            return false;
        
        unordered_map<char, int> mpS1;
        for(auto &s : s1)
        {
            mpS1[s]++;
        }

        int j = 0;
        for(int i = 0; i < s2.length(); i++)
        {
            auto itr = mpS1.find(s2[i]);
            auto cpMap = mpS1;
            for(int k = i; k < s2.size() && cpMap.size() != 0; k++)
            {
                if(cpMap.find(s2[k]) == cpMap.end())
                {
                    break;
                }
                --cpMap[s2[k]];
                if(cpMap[s2[k]] == 0) cpMap.erase(s2[k]);
                if(cpMap.size() == 0) return true;
            }
        }
        return false;
    }
*/
};