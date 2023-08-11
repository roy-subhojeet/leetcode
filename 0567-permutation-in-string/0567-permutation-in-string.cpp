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
};