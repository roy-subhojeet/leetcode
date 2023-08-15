class Solution {
public:
    string minWindow(string s, string t) {
        // If the length of t is greater than s, it's impossible to find a substring in s that contains t.
        if (t.size() > s.size()) {
            return "";
        }
        
        // Create a map to store the frequency of each character in t.
        unordered_map<char, int> tMap;
        for (char c : t) {
            ++tMap[c];
        }
        
        // Create a map to store the frequency of each character in the current window of s.
        unordered_map<char, int> resMap;
        
        // Initialize pointers and counters for the sliding window approach.
        int left = 0, right = 0, required = tMap.size(), formed = 0;
        int minLen = INT_MAX, minLeft = 0;

        // Start expanding the right end of the sliding window.
        while (right < s.size()) {
            char c = s[right];
            // Increase the count of the current character in the window's map.
            ++resMap[c];
            
            // If this character is needed and it meets the required count, increase the formed count.
            if (tMap.find(c) != tMap.end() && resMap[c] == tMap[c]) {
                ++formed;
            }

            // Try to contract the window from the left.
            while (formed == required) {
                char temp = s[left];
                
                // Update the result if this window is smaller than the previously found smallest window.
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                // Decrease the count of the leftmost character of the window.
                --resMap[temp];
                
                // Check if by removing this character, we are breaking the requirement.
                if (tMap.find(temp) != tMap.end() && resMap[temp] < tMap[temp]) {
                    --formed;
                }

                // Move the left end of the window.
                ++left;
            }

            // Move the right end of the window.
            ++right;
        }

        // Return the smallest window or "" if no window was found.
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
