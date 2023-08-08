class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0;
        unordered_map<char, int> charCount;
        int maxCount = 0; // To keep track of the max character count within the window
        int maxLength = 0;

        while (right < n) {
            char currentChar = s[right];
            // Increment the count of the current character
            charCount[currentChar]++;
            // Update maxCount if the current character's count is greater
            maxCount = max(maxCount, charCount[currentChar]);

            // Check if the number of replacements needed is greater than k
            if (right - left + 1 - maxCount > k) {
                char leftChar = s[left];
                // Decrement the count of the left character in the window
                charCount[leftChar]--;
                // If the left character was contributing to maxCount, recalculate maxCount
                if (charCount[leftChar] + 1 == maxCount) {
                    maxCount = 0;
                    for (const auto& entry : charCount) {
                        maxCount = max(maxCount, entry.second);
                    }
                }
                // Move the left pointer of the window
                left++;
            }

            // Update the maximum length found so far
            maxLength = max(maxLength, right - left + 1);
            // Move the right pointer of the window
            right++;
        }

        return maxLength;
    }
};